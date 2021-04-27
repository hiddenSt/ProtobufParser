include(FetchContent)

# argparse
FetchContent_Declare(
  argparse
  GIT_REPOSITORY https://github.com/p-ranav/argparse
  GIT_TAG master
)

FetchContent_GetProperties(argparse)

if (NOT ${argparse}_POPULATED)
  FetchContent_Populate(argparse)
  add_subdirectory(${argparse_SOURCE_DIR} ${argparse_BINARY_DIR})
endif()

get_filename_component(EXAMPLE_INCLUDE_PATH ".." ABSOLUTE)

add_executable(protobuf_parser_utility main.cpp)

target_link_libraries(protobuf_parser_utility PUBLIC protobuf_parser argparse)
target_include_directories(protobuf_parser_utility PRIVATE "${EXAMPLE_INCLUDE_PATH}")
