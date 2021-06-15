cmake_minimum_required(VERSION 3.14)
project(protobuf_parser VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

option(PROTOBUF_PARSER_DEVELOPER "ProtobufParser development mode" OFF)
option(PROTOBUF_PARSER_TESTS "Enable ProtobufParser tests" OFF)
option(PROTOBUF_PARSER_CONSOLE_UTILITY "Build console utility tool" OFF)

add_subdirectory(protobuf_parser)

if (PROTOBUF_PARSER_CONSOLE_UTILITY)
  add_subdirectory(console_utility)
endif()

if (PROTOBUF_PARSER_TESTS OR PROTOBUF_PARSER_DEVELOPER)
  add_subdirectory(tests)
endif ()