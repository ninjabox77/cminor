/**
 * Copyright 2009. All rights reserved.
 * Use of this source code is governed by the MIT
 * license that can be found in the LICENSE file.
 *
 * \author Ben Cisneros
 * \version 1.0
 */

#include "minor-file.h"

namespace lex
{
  RaiiFile::RaiiFile (const char *filename)
      : filename (filename)
  {
    if (strcmp (filename, "-") == 0)
      file = stdin;
    else
      file = fopen (filename, "r");
  }

  RaiiFile::RaiiFile (FILE *raw, const char *filename)
      : file (raw), filename (filename)
  {}

  RaiiFile::RaiiFile (RaiiFile &&other) noexcept
      : file (other.file), filename (other.filename)
  {
    other.file = nullptr;
  }

  RaiiFile &RaiiFile::operator= (RaiiFile &&other) noexcept
  {
    close ();
    file = other.file;
    filename = other.filename;
    other.file = nullptr;
    return *this;
  }

  RaiiFile::~RaiiFile ()
  {
    close ();
  }

  FILE *RaiiFile::get_raw ()
  {
    return file;
  }

  const char *RaiiFile::get_filename ()
  {
    return filename;
  }

  bool RaiiFile::is_ok () const
  {
    return file;
  }

  void RaiiFile::close ()
  {
    if (file != nullptr && file != stdin)
      fclose (file);
  }
}