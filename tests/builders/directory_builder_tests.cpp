#include <gtest/gtest.h>

#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(DirectoryBuilderTests, CanCreate) {
  ASSERT_NO_THROW(protobuf_parser::builders::DirectoryBuilder{});
}

TEST(DirectoryBuilderTests, CanSetUpPath) {
  std::filesystem::path dir_path{"dir_path/cool_path"};
  protobuf_parser::builders::DirectoryBuilder builder{};
  builder.SetUpPath(dir_path);
  ASSERT_EQ(builder.GetDirectory().GetPath(), dir_path);
}

TEST(DirectoryBuilderTests, CanSetUpParent) {
  std::filesystem::path parent_path{"parent/dir/path"};
  std::filesystem::path child_path{"parent/dir/path/child"};

  protobuf_parser::builders::DirectoryBuilder parent_builder{};
  protobuf_parser::builders::DirectoryBuilder child_builder{};

  parent_builder.SetUpPath(parent_path);
  child_builder.SetUpPath(child_path);

  auto parent_dir = std::move(parent_builder.GetDirectory());

  child_builder.SetUpParent(&parent_dir);

  auto child_dir = std::move(child_builder.GetDirectory());
  ASSERT_EQ(&child_dir.GetParentDirectory(), &parent_dir);
}

TEST(DirectoryBuilderTests, MethodIsParentOfReturnsTrueIfArgumentIsChild) {
  std::filesystem::path parent_path{"parent/dir/path"};
  std::filesystem::path child_path{"parent/dir/path/child"};

  protobuf_parser::builders::DirectoryBuilder parent_builder{};

  parent_builder.SetUpPath(parent_path);

  ASSERT_TRUE(parent_builder.IsParentOf(child_path));
}

TEST(DirectoryBuilderTests, MethodIsParentOfReturnsFalseIfArgumentIsNotDirectChild) {
  std::filesystem::path parent_path{"parent/dir/path"};
  std::filesystem::path child_path{"parent/dir/path/child/grand_child"};

  protobuf_parser::builders::DirectoryBuilder parent_builder{};

  parent_builder.SetUpPath(parent_path);

  ASSERT_FALSE(parent_builder.IsParentOf(child_path));
}

TEST(DirectoryBuilderTests, MethodIsParentOfReturnsFalseIfArgumentIsNotChild) {
  std::filesystem::path parent_path{"parent/dir/path"};
  std::filesystem::path child_path{"really/another/dir/path"};

  protobuf_parser::builders::DirectoryBuilder parent_builder{};

  parent_builder.SetUpPath(parent_path);

  ASSERT_FALSE(parent_builder.IsParentOf(child_path));
}

}  // namespace tests