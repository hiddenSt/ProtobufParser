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

add_executable(run_proto_buff_parser_tests "${TESTS_SOURCES}")

target_include_directories(run_proto_buff_parser_tests
  PRIVATE
  "${gtest_SOURCE_DIR}/include"
  "${gtest_SOURCE_DIR}"
  "${proto_buff_parser_SOURCE_DIR}"
  )
target_link_libraries(run_proto_buff_parser_tests PRIVATE gtest gtest_main)
target_link_libraries(run_proto_buff_parser_tests PRIVATE proto_buff_parser)

if (PROTO_BUFF_PARSER_DEVELOPER)

  if(CLANG_FORMAT_TOOL)
    add_clang_format_target(tests_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${TESTS_SOURCES})
  endif()

endif()