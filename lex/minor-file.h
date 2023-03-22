/**
 * Copyright 2009. All rights reserved.
 * Use of this source code is governed by the MIT
 * license that can be found in the LICENSE file.
 *
 * \author Ben Cisneros
 * \version 1.0
 */

#ifndef _MINOR_FILE_H_
#define _MINOR_FILE_H_

#include "include/minor-impl.h"

namespace lex
{
  class RaiiFile {
   public:
    explicit RaiiFile (const char *filename);
    explicit RaiiFile (FILE *raw, const char *filename = nullptr);

    RaiiFile (const RaiiFile &other) = delete;
    RaiiFile &operator= (const RaiiFile &other) = delete;
    RaiiFile (RaiiFile &&other) noexcept;
    RaiiFile &operator= (RaiiFile &&other) noexcept;
    ~RaiiFile ();
    FILE *get_raw ();
    const char *get_filename ();
    [[nodiscard]] bool is_ok () const;

   private:
    FILE *file;
    const char *filename;

    void close ();
  };
}

#endif // _MINOR_FILE_H_
