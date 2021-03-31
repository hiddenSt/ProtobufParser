
add_executable(run_proto_buff_parser_tests google_test_check.cpp)

target_include_directories(run_proto_buff_parser_tests PRIVATE "${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}" "${proto_buff_parser_SOURCE_DIR}")
target_link_libraries(run_proto_buff_parser_tests PRIVATE gtest gtest_main)
target_link_libraries(run_proto_buff_parser_tests PRIVATE proto_buff_parser)