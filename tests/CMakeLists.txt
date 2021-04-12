set(TESTS_SOURCES
  file_tests.cpp
  field_tests.cpp
  directory_tests.cpp
  package_tests.cpp
  message_tests.cpp
  protobuf_storage_tests.cpp
)

set(UTIL_SOURCES
  util/mock_multiple_error_collector.cpp
  util/mock_multiple_error_collector.hpp protobuf_parser_tests.cpp)

add_executable(run_protobuf_parser_tests "${TESTS_SOURCES}" "${UTIL_SOURCES}")

target_include_directories(run_protobuf_parser_tests
  PRIVATE
  "${gtest_SOURCE_DIR}/include"
  "${gtest_SOURCE_DIR}"
  "${protobuf_parser_SOURCE_DIR}"
  )
target_link_libraries(run_protobuf_parser_tests PRIVATE gtest gtest_main)
target_link_libraries(run_protobuf_parser_tests PRIVATE protobuf_parser)

if (PROTOBUF_PARSER_DEVELOPER)

  if(CLANG_FORMAT_TOOL)
    add_clang_format_target(tests_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${TESTS_SOURCES} ${UTIL_SOURCES})
  endif()

endif()