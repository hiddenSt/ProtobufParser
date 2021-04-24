#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>

namespace tests {

class FileTests : public ::testing::Test {
 protected:
  FileTests()
      : inner_dir_path("outer_dir/inner_dir"),
        outer_dir_path("outer_dir"),
        file_path_("outer_dir/inner_dir/file.proto") {}

  void SetUp() override {
    SetUpDirectories();
    SetUpPackages();
    SetUpFile();
  }

  void TearDown() override {

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
    file_builder.SetUpPath(file_path_);
    file_builder.SetUpPackage(&child_package_);
    file_builder.SetUpDirectory(&inner_dir_);
    file_ = std::move(file_builder.GetFile());
  }


  std::filesystem::path inner_dir_path;
  std::filesystem::path outer_dir_path;
  std::string parent_package_name_;
  std::string child_package_name_;
  std::filesystem::path file_path_;
  protobuf_parser::Directory outer_dir_;
  protobuf_parser::Directory inner_dir_;
  protobuf_parser::Package parent_package_;
  protobuf_parser::Package child_package_;
  protobuf_parser::File file_;
};


TEST_F(FileTests, CanGetFileName) {
  ASSERT_EQ(file_.GetName(), file_path_.filename().string());
}

TEST_F(FileTests, CanGetFilePath) {
  ASSERT_EQ(file_.GetPath(), file_path_);
}

TEST_F(FileTests, CanGetFileDirectory) {
  ASSERT_EQ(file_.GetDirectory().GetPath(), inner_dir_.GetPath());
}

TEST_F(FileTests, CanGetFilePackage) {
  ASSERT_EQ(file_.GetPackage().GetId(), child_package_.GetId());
  ASSERT_EQ(file_.GetPackage().GetName(), child_package_.GetName());
}

}  // namespace tests
