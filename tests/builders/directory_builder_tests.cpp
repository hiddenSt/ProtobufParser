#include <gtest/gtest.h>

#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(DirectoryBuilderTests, CanCreate) {
  ASSERT_NO_THROW(protobuf_parser::builders::DirectoryBuilder{});
}

TEST(DirectoryBuilderTests, CanSetUpName) {
  std::string name{"dir_name"};
  protobuf_parser::builders::DirectoryBuilder builder{};
  builder.SetUpPath(name);
  ASSERT_EQ(builder.GetDirectory().GetName(), name);
}

TEST(DirectoryBuilderTests, CanSetUpParent) {
  std::string parent_name{"dir_name"};
  std::string child_name{"child"};

  protobuf_parser::builders::DirectoryBuilder parent_builder{};
  protobuf_parser::builders::DirectoryBuilder child_builder{};

  parent_builder.SetUpPath(parent_name);
  child_builder.SetUpPath(child_name);

  auto parent_dir = std::move(parent_builder.GetDirectory());

  child_builder.SetUpParent(&parent_dir);

  auto child_dir = std::move(child_builder.GetDirectory());
  ASSERT_EQ(&child_dir.GetParentDirectory(), &parent_dir);
}

}  // namespace tests