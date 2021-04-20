#include <gtest/gtest.h>

#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(FileBuilderTests, CanCreate) {
  ASSERT_NO_THROW(protobuf_parser::builders::FileBuilder{});
}

TEST(FileBuilderTests, CanSetUpName) {
  std::string file_name{"file_name"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpName(file_name);

  ASSERT_EQ(builder.GetFile().GetName(), file_name);
}

TEST(FileBuilderTests, CanSetUpPackage) {
  std::string package_name{"package_name"};
  std::string file_name{"file_name"};
  protobuf_parser::builders::FileBuilder file_builder{};
  file_builder.SetUpName(file_name);
  protobuf_parser::builders::PackageBuilder package_builder{};
  package_builder.SetUpName(package_name);
  auto package = std::move(package_builder.GetPackage());

  file_builder.SetUpPackage(&package);

  auto file = std::move(file_builder.GetFile());
  ASSERT_EQ(&file.GetPackage(), &package);
}

TEST(FileBuildetTests, CanSetUpDirectory) {
  std::string directory_name{"directory_name"};
  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  directory_builder.SetUpName(directory_name);
  auto directory = std::move(directory_builder.GetDirectory());
}

TEST(FileBuilderTests, CanGetFile) {

}

}