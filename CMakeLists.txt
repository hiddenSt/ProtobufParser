cmake_minimum_required(VERSION 3.14)
project(project_name VERSION 1.0)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

option(PROJECT_NAME_DEVELOPER "PROJECT_NAME development mode" OFF)
option(PROJECT_NAME_TESTS "Enable PROJECT_NAME tests" OFF)

add_subdirectory(third-party)

add_subdirectory(tests)
