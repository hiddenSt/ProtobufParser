#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

class FileTests : public ::testing::Test {
 protected:
  void SetUp() override {
    SetUpTestData();
    SetUpDirectories();
    SetUpPackages();
    SetUpFile();
  }

  void TearDown() override {

  }

  void SetUpTestData() {

  }

  void SetUpDirectories() {
    protobuf_parser::builders::DirectoryBuilder outer_directory_builder{};
    outer_directory_builder.SetUpPath(outer_dir_path);
    outer_dir_ = std::move(outer_directory_builder.GetDirectory());

    protobuf_parser::builders::DirectoryBuilder inner_directory_builder{};
    inner_directory_builder.SetUpPath(inner_dir_path);
    inner_directory_builder.SetUpParent(&outer_dir_);
    inner_dir_ = std::move(inner_directory_builder.GetDirectory());
  }

  void SetUpPackages() {
    protobuf_parser::builders::PackageBuilder parent_package_builder{};
    parent_package_builder.SetUpName(parent_package_name_);
    parent_package_ = std::move(parent_package_builder.GetPackage());

    protobuf_parser::builders::PackageBuilder child_package_builder{};
    child_package_builder.SetUpName(child_package_name_);
    child_package_builder.SetUpParent(&parent_package_);
    child_package_ = std::move(child_package_builder.GetPackage());
  }

  void SetUpFile() {
    protobuf_parser::builders::FileBuilder file_builder{};
    file_builder.SetUpPath(file_name_);
    file_builder.SetUpPackage(&child_package_);
    file_builder.SetUpDirectory(&inner_dir_);
    file_ = std::move(file_builder.GetFile());
  }


  std::filesystem::path inner_dir_path;
  std::filesystem::path outer_dir_path;
  std::string parent_package_name_;
  std::string child_package_name_;
  std::string file_name_;
  protobuf_parser::Directory outer_dir_;
  protobuf_parser::Directory inner_dir_;
  protobuf_parser::Package parent_package_;
  protobuf_parser::Package child_package_;
  protobuf_parser::File file_;
};


TEST_F(FileTests, CanGetFileName) {
  ASSERT_EQ(file_.GetName(), file_name_);
}

TEST_F(FileTests, CanGetFilePath) {
  std::string file_path = inner_dir_.GetPath().string() + "/";
  ASSERT_EQ(file_.GetPath(), file_path);
}

TEST_F(FileTests, CanGetFileDirectory) {

}

}  // namespace tests
