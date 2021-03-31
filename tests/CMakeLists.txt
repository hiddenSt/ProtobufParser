
add_executable(run_project_name_tests google_test_check.cpp)

target_include_directories(run_project_name_tests PRIVATE "${gtest_SOURCE_DIR}/include" "${gtest_SOURCE_DIR}")
target_link_libraries(run_project_name_tests PRIVATE gtest gtest_main)