#include <gtest/gtest.h>
#include <protobuf_parser/parse_elements/directory.hpp>

namespace tests {

TEST(DirectoryTests, CanGetParentDirectory) {
  std::string parent_dir_name{"CoolName"};
  std::string dir_name{"cool_name"};
  protobuf_parser::Directory parent_directory{parent_dir_name};
  protobuf_parser::Directory dir{dir_name, &parent_directory};

  ASSERT_EQ(dir.GetParentDirectory()->GetName(), parent_dir_name);
}



}