#include <gtest/gtest.h>

#include <../proto_buff_parser/file.hpp>

namespace tests {

TEST(FileTests, CanGetFileName) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  proto_buff_parser::File file{file_name, file_path};
  ASSERT_EQ(file.GetName(), file_name);
}

TEST(FileTests, CanGetFilePath) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  proto_buff_parser::File file{file_name, file_path};
  ASSERT_EQ(file.GetPath(), file_path);
}

}  // namespace tests
