cmake_minimum_required(VERSION 3.24)
project(minor)

include_directories(../minor)

set(CMAKE_CXX_STANDARD 17)

add_executable(minor main.cpp include/minor-impl.h lex/minor_token.cc lex/minor_token.h lex/minor_file.cc lex/minor_file.h lex/minor_lexer.cc lex/minor_lexer.h)
