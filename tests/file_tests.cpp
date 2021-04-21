#include <gtest/gtest.h>

#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(FileTests, CanGetFileName) {
  std::string file_name{"FileName1"};
  protobuf_parser::builders::FileBuilder builder{};
  builder.SetUpName(file_name);
  auto file = std::move(builder.GetFile());
  ASSERT_EQ(file.GetName(), file_name);
}

TEST(FileTests, CanGetFilePath) {
  std::string file_name{"FileName1"};
  std::string outer_dir_name{"outer"};
  std::string inner_dir_name{"outer/inner"};
  std::string package_name{"Hello world"};

  protobuf_parser::builders::DirectoryBuilder outer_dir_builder{};
  protobuf_parser::builders::DirectoryBuilder inner_dir_builder{};
  protobuf_parser::builders::PackageBuilder package_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};

  outer_dir_builder.SetUpName(outer_dir_name);
  auto outer_dir = std::move(outer_dir_builder.GetDirectory());
  inner_dir_builder.SetUpName(inner_dir_name);
  inner_dir_builder.SetUpParent(&outer_dir);
  auto inner_dir = std::move(inner_dir_builder.GetDirectory());

  package_builder.SetUpName(package_name);

  auto package = std::move(package_builder.GetPackage());

  file_builder.SetUpPackage(&package);
  file_builder.SetUpDirectory(&inner_dir);

  auto file = std::move(file_builder.GetFile());

  std::string file_path = inner_dir.GetName() + "/";
  ASSERT_EQ(file.GetPath(), file_path);
}

}  // namespace tests
