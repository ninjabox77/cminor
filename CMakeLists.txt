cmake_minimum_required(VERSION 3.24)
project(minor)

include_directories(../minor)

set(CMAKE_CXX_STANDARD 17)

add_executable(minor main.cpp include/minor-impl.h lex/minor-token.cc lex/minor-token.h lex/minor-file.cc lex/minor-file.h lex/minor-lexer.cc lex/minor-lexer.h)
