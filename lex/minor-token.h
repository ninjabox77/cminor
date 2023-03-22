/**
 * Copyright 2009. All rights reserved.
 * Use of this source code is governed by the MIT
 * license that can be found in the LICENSE file.
 *
 * \author Ben Cisneros
 * \version 1.0
 */

#ifndef _MINOR_TOKEN_H_
#define _MINOR_TOKEN_H_

#include "include/minor-impl.h"

namespace lex
{
// A simple designated initializer for an enum that represents
// different kinds of tokens in the language.
#define TOKEN_LIST                                                   \
  TOKEN (END_OF_FILE             , "end of file")                    \
  \
  TOKEN_KEYWORD (ARRAY           , "Array")                          \
  TOKEN_KEYWORD (CAST            , "Cast")                           \
  TOKEN_KEYWORD (LENGTH          , "Length")                         \
  TOKEN_KEYWORD (MATCH           , "Match")                          \
  TOKEN_KEYWORD (NEXT            , "Next")                           \
  TOKEN_KEYWORD (PREV            , "Prev")                           \
  \
  TOKEN_KEYWORD (ABSTR           , "abstr")                          \
  TOKEN_KEYWORD (CHOICE          , "choice")                         \
  TOKEN_KEYWORD (ELSE            , "else")                           \
  TOKEN_KEYWORD (FOR             , "for")                            \
  TOKEN_KEYWORD (IN              , "in")                             \
  TOKEN_KEYWORD (INSTOF          , "instof")                         \
  TOKEN_KEYWORD (MAIN            , "main")                           \
  TOKEN_KEYWORD (OTHER           , "other")                          \
  TOKEN_KEYWORD (PURE            , "pure")                           \
  TOKEN_KEYWORD (RETYPE          , "retype")                         \
  TOKEN_KEYWORD (TYPE            , "type")                           \
  \
  TOKEN_KEYWORD (ADDTO           , "addto")                          \
  TOKEN_KEYWORD (CLASS           , "class")                          \
  TOKEN_KEYWORD (ELSEIF          , "elseif")                         \
  TOKEN_KEYWORD (FUNC            , "func")                           \
  TOKEN_KEYWORD (INOUT           , "inout")                          \
  TOKEN_KEYWORD (LAST            , "last")                           \
  TOKEN_KEYWORD (METHOD          , "method")                         \
  TOKEN_KEYWORD (OUT             , "out")                            \
  TOKEN_KEYWORD (RECURS          , "recurs")                         \
  TOKEN_KEYWORD (SCALAR          , "scalar")                         \
  TOKEN_KEYWORD (UNINIT          , "uninit")                         \
  \
  TOKEN_KEYWORD (APPEND          , "append")                         \
  TOKEN_KEYWORD (CONST           , "const")                          \
  TOKEN_KEYWORD (ENDL            , "endl")                           \
  TOKEN_KEYWORD (GLOBAL          , "global")                         \
  TOKEN_KEYWORD (INREV           , "inrev")                          \
  TOKEN_KEYWORD (LOCAL           , "local")                          \
  TOKEN_KEYWORD (MULTI           , "multi")                          \
  TOKEN_KEYWORD (PROTECT         , "protect")                        \
  TOKEN_KEYWORD (REMOVE          , "remove")                         \
  TOKEN_KEYWORD (SET             , "set")                            \
  TOKEN_KEYWORD (UNTIL           , "until")                          \
  \
  TOKEN_KEYWORD (CALL            , "call")                           \
  TOKEN_KEYWORD (DISCR           , "discr")                          \
  TOKEN_KEYWORD (FINAL           , "final")                          \
  TOKEN_KEYWORD (IF              , "if")                             \
  TOKEN_KEYWORD (INSERT          , "insert")                         \
  TOKEN_KEYWORD (LOOP            , "loop")                           \
  TOKEN_KEYWORD (ON              , "on")                             \
  TOKEN_KEYWORD (PUBLIC          , "public")                         \
  TOKEN_KEYWORD (RETURN          , "return")                         \
  TOKEN_KEYWORD (STOP            , "stop")                           \
  TOKEN_KEYWORD (VOID            , "void")                           \
  TOKEN_KEYWORD (BOOL            , "BOOL")                           \
  TOKEN_KEYWORD (CHAR            , "CHAR")                           \
  TOKEN_KEYWORD (INT             , "INT")                            \
  TOKEN_KEYWORD (FLOAT           , "FLOAT")                          \
  TOKEN_KEYWORD (STRING          , "STRING")                         \
  \
  TOKEN (SINGLE_QUOTE            , "'")                              \
  TOKEN (DOUBLE_QUOTE            , "\"")                             \
  TOKEN (IDENTIFIER              , "identifier")                     \
  TOKEN (INT_LITERAL             , "integer literal")                \
  TOKEN (FLOAT_LITERAL           , "float literal")                  \
  TOKEN (STRING_LITERAL          , "string literal")                 \
  TOKEN (CHAR_LITERAL            , "char literal")                   \
  \
  TOKEN (LPAREN                  , "(")                              \
  TOKEN (RPAREN                  , ")")                              \
  TOKEN (LBRACE                  , "{")                              \
  TOKEN (RPRACE                  , "}")                              \
  TOKEN (LBRACK                  , "[")                              \
  TOKEN (RBRACK                  , "]")                              \
  \
  TOKEN (ATSIGN                  , "@")                              \
  TOKEN (HASH                    , "#")                              \
  TOKEN (DOLLAR                  , "$")                              \
  TOKEN (SEMI                    , ";")                              \
  TOKEN (COMMA                   , ",")                              \
  \
  TOKEN (QUEST                   , "?")                              \
  TOKEN (SCOPE_RESOLUTION        , "::")                             \
  TOKEN (COLON                   , ":")                              \
  TOKEN (DOT                     , ".")                              \
  TOKEN (ELLIPSIS                , "...")                            \
  \
  TOKEN (EQ                      , "=")                              \
  TOKEN (MULTEQ                  , "*=")                             \
  TOKEN (DIVEQ                   , "/=")                             \
  TOKEN (MODEQ                   , "%=")                             \
  TOKEN (PLUSEQ                  , "+=")                             \
  TOKEN (MINUSEQ                 , "-=")                             \
  TOKEN (LSHIFTEQ                , "<<=")                            \
  TOKEN (RSHIFTEQ                , ">>=")                            \
  TOKEN (RRSHIFTEQ               , ">>>=")                           \
  TOKEN (ANDEQ                   , "&=")                             \
  TOKEN (XOREQ                   , "^=")                             \
  TOKEN (OREQ                    , "|=")                             \
  TOKEN (RETURN_TYPE             , "=>")                             \
  \
  TOKEN (GT                      , ">")                              \
  TOKEN (LT                      , "<")                              \
  TOKEN (EQEQ                    , "=")                              \
  TOKEN (LTEQ                    , "<=")                             \
  TOKEN (GTEQ                    , ">=")                             \
  TOKEN (NOTEQ                   , "!=")                             \
  \
  TOKEN (LSHIFT                  , "<<")                             \
  TOKEN (RSHIFT                  , ">>")                             \
  TOKEN (RRSHIFT                 , ">>>")                            \
  TOKEN (ANDAND                  , "&&")                             \
  TOKEN (OROR                    , "||")                             \
  TOKEN (PLUS                    , "+")                              \
  TOKEN (MINUS                   , "-")                              \
  TOKEN (MULT                    , "*")                              \
  TOKEN (DIV                     , "/")                              \
  TOKEN (AND                     , "&")                              \
  TOKEN (OR                      , "|")                              \
  TOKEN (XOR                     , "^")                              \
  TOKEN (MOD                     , "%")                              \
  \
  TOKEN (NOT                     , "!")                              \
  TOKEN (COMP                    , "~")                              \
  TOKEN (DPLUS                   , "++")                             \
  TOKEN (DMINUS                  , "--")                             \
  TOKEN (DMULT                   , "**")

  // Contains all tokens type.
  enum TokenID {
#define TOKEN(name, _) name,
#define TOKEN_KEYWORD(name, descr) TOKEN(name, descr)
      TOKEN_LIST
#undef  TOKEN_KEYWORD
#undef  TOKEN
  };

  // Contains a string representation of each Token type.
  static const char *token_names[] = {
#define TOKEN(name, descr) descr,
#define TOKEN_KEYWORD(name, descr) TOKEN(name, descr)
      TOKEN_LIST
#undef  TOKEN_KEYWORD
#undef  TOKEN
  };

  // Represents a Token returned from the lexer.
  class Token {
   public:
    // Represents the position and line in which a Token appears.
    struct Location {
        int column;
        int line;
    };

    // No default constructor.
    Token () = delete;

    // Do not copy tokens.
    Token (const Token &other) = delete;
    Token &operator= (const Token &other) = delete;

    // Allow moving tokens.
    Token (Token &&other) = default;
    Token &operator= (Token &&other) = default;
    ~Token () = default;

    // Makes and returns a new Token with null string.
    static std::shared_ptr<Token> make (TokenID id, Token::Location position)
    {
      return std::shared_ptr<Token> (new Token (id, position));
    }

    // Makes and returns a new Token of type IDENTIFIER.
    static std::shared_ptr<Token> make_identifier (Token::Location position, std::string &&str)
    {
      return std::shared_ptr<Token> (new Token (IDENTIFIER, position, std::move (str)));
    }

    // Makes and returns a new Token of type INT_LITERAL.
    static std::shared_ptr<Token> make_int (Token::Location position, std::string &&str)
    {
      return std::shared_ptr<Token> (new Token (INT_LITERAL, position, std::move (str)));
    }

    // Makes and returns a new Token of type INT_LITERAL.
    static std::shared_ptr<Token> make_float (Token::Location position, std::string &&str)
    {
      return std::shared_ptr<Token> (new Token (FLOAT_LITERAL, position, std::move (str)));
    }

    // Makes and returns a new Token of type INT_LITERAL.
    static std::shared_ptr<Token> make_string (Token::Location position, std::string &&str)
    {
      return std::shared_ptr<Token> (new Token (STRING_LITERAL, position, std::move (str)));
    }

    // Makes and returns a new Token of type INT_LITERAL.
    static std::shared_ptr<Token> make_char (Token::Location position, std::string &&str)
    {
      return std::shared_ptr<Token> (new Token (CHAR_LITERAL, position, std::move (str)));
    }

    // Makes and returns a Location for the Token
    static Location make_location (int column, int line)
    {
      return Location{column, line};
    }

    // Returns the id of the Token
    [[nodiscard]] TokenID get_id () const;

    // Returns the Location of the Token
    [[nodiscard]] Location get_location () const;

    // Returns the description of the Token
    [[nodiscard]] const char *get_token_description () const;

    // Returns whether the Token has a string
    [[nodiscard]] bool has_str () const;

    // Returns whether the Token should have a string
    [[nodiscard]] bool should_have_str () const;

    // Returns whether the Token is a literal of any type
    [[nodiscard]] bool is_literal () const;

   private:
    // Token kind.
    TokenID id;
    // Token Location.
    Location position;
    // Associated text to Token.
    std::unique_ptr<std::string> str;

    // Token constructors.
    Token (TokenID id, Location position);
    Token (TokenID id, Location position, std::string &&str);
    Token (TokenID id, Location position, char c);
  };

  // Returns the description of the Token
  const char *get_token_description (TokenID id);
}

#endif // _MINOR_TOKEN_H_
