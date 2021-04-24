#include <gtest/gtest.h>
#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(DirectoryTests, CanGetDirectoryPath) {
  std::filesystem::path dir_path{"/cool_path/dir"};
  protobuf_parser::builders::DirectoryBuilder builder{};
  builder.SetUpPath(dir_path);

  auto directory = std::move(builder.GetDirectory());

  ASSERT_EQ(directory.GetPath(), dir_path);
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

  ASSERT_EQ(directory.GetParentDirectory().GetPath(), parent_dir_name);
}

}  // namespace tests