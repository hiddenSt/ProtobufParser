cmake_minimum_required(VERSION 3.14)
project(ProtobufParser VERSION 1.0)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

option(PROTOBUF_PARSER_DEVELOPER "ProtobufParser development mode" OFF)
option(PROTOBUF_PARSER_TESTS "Enable ProtobufParser tests" OFF)

add_subdirectory(third-party)

add_subdirectory(protobuf_parser)

if (PROTOBUF_PARSER_TESTS OR PROTOBUF_PARSER_DEVELOPER)
  add_subdirectory(tests)
endif ()