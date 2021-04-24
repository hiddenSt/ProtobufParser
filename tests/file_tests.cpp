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
      : dir_path_("outer_dir"),
        package_name_("package_name"),
        file_path_("outer_dir/file.proto") {}

  void SetUp() override {
    SetUpDirectory();
    SetUpPackage();
    SetUpFile();
  }

  void TearDown() override {

  }

  void SetUpDirectory() {
    protobuf_parser::builders::DirectoryBuilder outer_directory_builder{};
    outer_directory_builder.SetUpPath(dir_path_);
    dir_ = std::move(outer_directory_builder.GetDirectory());
  }

  void SetUpPackage() {
    protobuf_parser::builders::PackageBuilder package_builder{};
    package_builder.SetUpName(package_name_);
    package_ = std::move(package_builder.GetPackage());
  }

  void SetUpFile() {
    protobuf_parser::builders::FileBuilder file_builder{};
    file_builder.SetUpPath(file_path_);
    file_builder.SetUpDirectory(&dir_);
    file_builder.SetUpPackage(&package_);
    file_ = std::move(file_builder.GetFile());
  }

  std::filesystem::path dir_path_;
  std::string package_name_;
  std::filesystem::path file_path_;
  protobuf_parser::Directory dir_;
  protobuf_parser::Package package_;
  protobuf_parser::File file_;
};


TEST_F(FileTests, CanGetName) {
  ASSERT_NO_THROW(file_.GetName());
}

TEST_F(FileTests, MethodGetNameReturnsCorrectName) {
  ASSERT_EQ(file_.GetName(), file_path_.filename());
}

TEST_F(FileTests, CanGetFilePath) {
  ASSERT_NO_THROW(file_.GetPath());
}

TEST_F(FileTests, MethodGetPathReturnsCorrectPath) {
  ASSERT_EQ(file_.GetPath(), file_path_);
}

TEST_F(FileTests, CanGetFileDirectory) {
  ASSERT_NO_THROW(file_.GetDirectory());
}

TEST_F(FileTests, MethodGetDirectoryReturnsCorrectDirectory) {
  ASSERT_EQ(file_.GetDirectory().GetId(), dir_.GetId());
}

TEST_F(FileTests, CanGetFilePackage) {
  ASSERT_NO_THROW(file_.GetPackage());
}

TEST_F(FileTests, MethodGetPackageReturnsCorrectPackage) {
  ASSERT_EQ(file_.GetPackage().GetId(), package_.GetId());
}

}  // namespace tests
