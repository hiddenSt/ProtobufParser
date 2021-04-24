#include <gtest/gtest.h>
#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(DirectoryTests, CanGetDirectoryName) {
  std::string dir_name{"cool_name"};
  protobuf_parser::builders::DirectoryBuilder builder{};
  builder.SetUpPath(dir_name);

  auto directory = std::move(builder.GetDirectory());

  ASSERT_EQ(directory.GetName(), dir_name);
}

TEST(DirectoryTests, CanGetParentDirectory) {
  std::string parent_dir_name{"CoolName"};
  std::string dir_name{"cool_name"};
  protobuf_parser::builders::DirectoryBuilder child_builder;
  protobuf_parser::builders::DirectoryBuilder parent_builder;
  parent_builder.SetUpPath(parent_dir_name);
  child_builder.SetUpPath(dir_name);
  auto parent_directory = std::move(parent_builder.GetDirectory());

  child_builder.SetUpParent(&parent_directory);

  auto directory = std::move(child_builder.GetDirectory());

  ASSERT_EQ(directory.GetParentDirectory().GetName(), parent_dir_name);
}

}  // namespace tests