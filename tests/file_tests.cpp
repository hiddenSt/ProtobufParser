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

TEST(FileTests, ReturnsTrueIfCompareEqualFiles) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  protobuf_parser::File file{file_name, file_path};
  protobuf_parser::File file2{file};
  ASSERT_TRUE(file == file2);
}

TEST(FileTests, ReturnsFalseIfCompareFilesWithDifferentNames) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  protobuf_parser::File file{file_name, file_path};

  std::string file_name2{"File"};
  protobuf_parser::File file2{file_name2, file_path};

  ASSERT_FALSE(file == file2);
}

TEST(FileTests, ReturnsFalseIfCompareFilesWithDifferentPaths) {
  std::string file_name{"FileName1"};
  std::string file_path{"FilePath1"};
  protobuf_parser::File file{file_name, file_path};

  std::string file_path2{"DifferentFilePath"};
  protobuf_parser::File file2{file_name, file_path2};

  ASSERT_TRUE(file != file2);
}

}  // namespace tests
