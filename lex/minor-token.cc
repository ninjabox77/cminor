/**
 * Copyright 2009. All rights reserved.
 * Use of this source code is governed by the MIT
 * license that can be found in the LICENSE file.
 *
 * \author Ben Cisneros
 * \version 1.0
 */

#include "minor-token.h"

namespace lex
{
  const char *get_token_description (TokenID id)
  {
    return token_names[id];
  }

  Token::Token (TokenID id, Location position)
      : id (id), position (position), str (nullptr)
  {}

  Token::Token (TokenID id, Location position, std::string &&str)
      : id (id), position (position), str (new std::string (std::move (str)))
  {}

  Token::Token (TokenID id, Location position, char c)
      : id (id), position (position), str (new std::string (1, c))
  {}

  TokenID Token::get_id () const
  {
    return id;
  }

  Token::Location Token::get_location () const
  {
    return position;
  }

  const char *Token::get_token_description () const
  {
    return lex::get_token_description (id);
  }

  bool Token::has_str () const
  {
    return str != nullptr;
  }

  bool Token::should_have_str () const
  {
    return is_literal () || id == IDENTIFIER;
  }

  bool Token::is_literal () const
  {
    switch (id)
      {
        case INT_LITERAL:
        case FLOAT_LITERAL:
        case CHAR_LITERAL:
        case STRING_LITERAL:
          return true;
        default:
          return false;
      }
  }
}