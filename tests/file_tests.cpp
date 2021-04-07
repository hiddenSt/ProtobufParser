#include <gtest/gtest.h>

#include <protobuf_parser/parse_elements/file.hpp>

namespace tests {

TEST(FileTests, CanGetFileName) {
  std::string file_name{"FileName1"};
  protobuf_parser::Directory dir{"outer"};
  protobuf_parser::File file{file_name, &dir};
  ASSERT_EQ(file.GetName(), file_name);
}

TEST(FileTests, CanGetFilePath) {
  std::string file_name{"FileName1"};
  protobuf_parser::Directory outer_dir{"outer"};
  protobuf_parser::Directory inner_dir{"inner", &outer_dir};
  protobuf_parser::File file{file_name, &inner_dir};

  std::string file_path = "/" + outer_dir.GetName() + "/" + inner_dir.GetName();
  ASSERT_EQ(file.GetPath(), file_path);
}

TEST(FileTests, ReturnsTrueIfCompareEqualFiles) {
  std::string file_name{"FileName1"};
  protobuf_parser::Directory dir{"outer"};
  protobuf_parser::File file{file_name, &dir};
  protobuf_parser::File file2{file};
  ASSERT_TRUE(file == file2);
}

TEST(FileTests, ReturnsFalseIfCompareFilesWithDifferentNames) {
  std::string file_name{"FileName1"};
  protobuf_parser::Directory dir{"outer"};
  protobuf_parser::File file{file_name, &dir};

  std::string file_name2{"File"};
  protobuf_parser::File file2{file_name2, &dir};

  ASSERT_FALSE(file == file2);
}

TEST(FileTests, ReturnsFalseIfCompareFilesWithDifferentPaths) {
  std::string file_name{"FileName1"};
  protobuf_parser::Directory dir1{"outer"};
  protobuf_parser::File file{file_name, &dir1};

  protobuf_parser::Directory dir2{"different_dit"};
  protobuf_parser::File file2{file_name, &dir2};

  ASSERT_TRUE(file != file2);
}

}  // namespace tests
