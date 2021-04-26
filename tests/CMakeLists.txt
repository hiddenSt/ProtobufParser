include(FetchContent)

FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)

FetchContent_GetProperties(gtest)

if (NOT ${gtest}_POPULATED)
  FetchContent_Populate(gtest)
  add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BINARY_DIR})
endif()

set(TESTS_SOURCES
  file_tests.cpp
  field_tests.cpp
  directory_tests.cpp
  package_tests.cpp
  message_tests.cpp
  storage_tests.cpp
  parser_tests.cpp
  builders/message_builder_tests.cpp
  builders/package_builder_tests.cpp
  builders/directory_builder_tests.cpp
  builders/file_builder_tests.cpp
  builders/storage_builder_tests.cpp
  builders/enum_builder_tests.cpp view_tests.cpp)

set(TEST_UTIL util/test_serializer.hpp)

add_executable(run_protobuf_parser_tests "${TESTS_SOURCES}" "${TEST_UTIL}")

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