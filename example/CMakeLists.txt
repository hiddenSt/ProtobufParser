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

add_executable(example main.cpp)

target_link_libraries(example PRIVATE protobuf_parser argparse)
target_include_directories(example PRIVATE "${EXAMPLE_INCLUDE_PATH}")
