set(TESTS_SOURCES
  message_tests.cpp
  file_tests.cpp
  field_tests.cpp
  package_tests.cpp
  container/files_container_tests.cpp
  container/messages_container_tests.cpp
  container/packages_container_tests.cpp
  iterator/files_iterator_tests.cpp
  iterator/messages_iterator_tests.cpp
  iterator/packages_iterator_tests.cpp
  view/view_tests.cpp
  )

set(UTIL_SOURCES
  util/container/test_fields_container.hpp)

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