cmake_minimum_required(VERSION 3.14)
project(project_name VERSION 1.0)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

add_subdirectory(third-party)
add_subdirectory(tests)
