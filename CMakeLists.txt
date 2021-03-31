cmake_minimum_required(VERSION 3.14)
project(ProtoBuffParser VERSION 1.0)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

option(PROTO_BUFF_PARSER_DEVELOPER "ProtoBuffParser development mode" OFF)
option(PROTO_BUFF_PARSER_TESTS "Enable ProtoBuffParser tests" OFF)

add_subdirectory(third-party)

add_subdirectory(proto_buff_parser)

if (PROTO_BUFF_PARSER_TESTS OR PROTO_BUFF_PARSER_DEVELOPER)
  add_subdirectory(tests)
endif ()