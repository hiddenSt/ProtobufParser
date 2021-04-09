cmake_minimum_required(VERSION 3.14)
project(protobuf_parser VERSION 1.0)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

option(PROTOBUF_PARSER_DEVELOPER "ProtobufParser development mode" OFF)
option(PROTOBUF_PARSER_TESTS "Enable ProtobufParser tests" OFF)


add_subdirectory(third-party)

add_subdirectory(protobuf_parser)

add_subdirectory(example)

if (PROTOBUF_PARSER_TESTS OR PROTOBUF_PARSER_DEVELOPER)
  add_subdirectory(tests)
endif ()