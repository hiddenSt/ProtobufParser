#include <gtest/gtest.h>

#include <protobuf_parser/parse_elements/file.hpp>

namespace tests {

TEST(FileTests, CanGetFileName) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  protobuf_parser::File file{file_name, file_path};
  ASSERT_EQ(file.GetName(), file_name);
}

TEST(FileTests, CanGetFilePath) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  protobuf_parser::File file{file_name, file_path};
  ASSERT_EQ(file.GetPath(), file_path);
}

TEST(RemoveThisTest, LambdasTests) {
  decltype(auto) lambda = [](const int &a, const int& b){ return a - b > a*b; };
  std::vector<int> arr{10, 20, 5, -2, 5};
  std::sort(arr.begin(), arr.end(), lambda);
}

}  // namespace tests
