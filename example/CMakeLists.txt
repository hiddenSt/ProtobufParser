get_filename_component(EXAMPLE_INCLUDE_PATH ".." ABSOLUTE)

add_executable(example main.cpp)

target_link_libraries(example PRIVATE protobuf_parser)
target_include_directories(example PRIVATE "${EXAMPLE_INCLUDE_PATH}")
