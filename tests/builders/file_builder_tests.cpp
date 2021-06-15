#include <gtest/gtest.h>

#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

TEST(FileBuilderTests, CanCreate) {
  ASSERT_NO_THROW(protobuf_parser::builders::FileBuilder{});
}

TEST(FileBuilderTests, CanSetUpName) {
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder builder{};

  ASSERT_NO_THROW(builder.SetUpPath(file_path));
}

TEST(FileBuilderTests, CanGetName) {
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);

  ASSERT_NO_THROW(builder.GetFile().GetName());
}

TEST(FileBuilderTests, MethodGetNameReturnsCorrectName) {
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);

  ASSERT_EQ(builder.GetFile().GetName(), file_path.string());
}

TEST(FileBuilderTests, CanSetUpPackageName) {
  std::filesystem::path file_path{"file_path"};
  std::string package_name{"package_name"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);
  ASSERT_NO_THROW(builder.SetUpPackageName(package_name));
}

TEST(FileBuilderTests, CanGetPackageName) {
  std::filesystem::path file_path{"file_path"};
  std::string package_name{"package_name"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);
  builder.SetUpPackageName(package_name);
  ASSERT_NO_THROW(builder.GetPackageName());
}

TEST(FileBuilderTests, MethodGetPackageNameReturnsCorrectPackageName) {
  std::filesystem::path file_path{"file_path"};
  std::string package_name{"package_name"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);
  builder.SetUpPackageName(package_name);
  ASSERT_EQ(builder.GetPackageName(), package_name);
}

TEST(FileBuilderTests, CanGetFile) {
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);
  ASSERT_NO_THROW(builder.GetFile());
}

TEST(FileBuilderTests, MethodCanGetFileReturnsCorrectFile) {
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder builder{};

  builder.SetUpPath(file_path);
  ASSERT_EQ(builder.GetFile().GetPath(), file_path);
}

TEST(FileBuilderTests, CanSetUpPackage) {
  std::string package_name{"package_name"};
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder file_builder{};
  file_builder.SetUpPath(file_path);
  protobuf_parser::builders::PackageBuilder package_builder{};
  package_builder.SetUpName(package_name);
  auto package = std::move(package_builder.GetPackage());

  ASSERT_NO_THROW(file_builder.SetUpPackage(&package));
}

TEST(FileBuilderTests, CanGetPackage) {
  std::string package_name{"package_name"};
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder file_builder{};
  file_builder.SetUpPath(file_path);
  protobuf_parser::builders::PackageBuilder package_builder{};
  package_builder.SetUpName(package_name);
  auto package = std::move(package_builder.GetPackage());

  file_builder.SetUpPackage(&package);

  auto file = std::move(file_builder.GetFile());
  ASSERT_NO_THROW(file.GetPackage());
}

TEST(FileBuilderTests, MethodGetPackageReturnsCorrectPackage) {
  std::string package_name{"package_name"};
  std::filesystem::path file_path{"file_path"};
  protobuf_parser::builders::FileBuilder file_builder{};
  file_builder.SetUpPath(file_path);
  protobuf_parser::builders::PackageBuilder package_builder{};
  package_builder.SetUpName(package_name);
  auto package = std::move(package_builder.GetPackage());

  file_builder.SetUpPackage(&package);

  auto file = std::move(file_builder.GetFile());
  ASSERT_EQ(file.GetPackage().GetName(), package.GetName());
  ASSERT_EQ(file.GetPackage().GetId(), package.GetId());
}

TEST(FileBuildetTests, CanSetUpDirectory) {
  std::filesystem::path directory_path{"directory_path"};
  std::filesystem::path file_path{"directory_path/file"};
  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};
  directory_builder.SetUpPath(directory_path);
  auto directory = std::move(directory_builder.GetDirectory());

  file_builder.SetUpPath(file_path);
  ASSERT_NO_THROW(file_builder.SetUpDirectory(&directory));
}

TEST(FileBuildetTests, CanGetDirectory) {
  std::filesystem::path directory_path{"directory_path"};
  std::filesystem::path file_path{"directory_path/file"};
  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};
  directory_builder.SetUpPath(directory_path);
  auto directory = std::move(directory_builder.GetDirectory());

  file_builder.SetUpPath(file_path);
  file_builder.SetUpDirectory(&directory);

  auto file = std::move(file_builder.GetFile());
  ASSERT_NO_THROW(file.GetDirectory());
}

TEST(FileBuildetTests, MethodGetDirectoryReturnsCorrectDirectory) {
  std::filesystem::path directory_path{"directory_path"};
  std::filesystem::path file_path{"directory_path/file"};
  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};
  directory_builder.SetUpPath(directory_path);
  auto directory = std::move(directory_builder.GetDirectory());

  file_builder.SetUpPath(file_path);
  file_builder.SetUpDirectory(&directory);

  auto file = std::move(file_builder.GetFile());
  ASSERT_EQ(file.GetDirectory().GetPath(), directory.GetPath());
  ASSERT_EQ(file.GetDirectory().GetId(), directory.GetId());
}

}  // namespace tests