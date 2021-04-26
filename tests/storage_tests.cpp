#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/storage.hpp>

#include <protobuf_parser/parser.hpp>

namespace tests {

class StorageTests : public ::testing::Test {
 protected:
  StorageTests() : parser_(std::filesystem::path("../../tests/protos")) {
  }

  void SetUp() override {
    parser_.Parse();
    storage_ = new protobuf_parser::Storage{std::move(parser_.GetStorage())};
  }

  void TearDown() override {
    delete storage_;
  }

  protobuf_parser::Storage* storage_;
  protobuf_parser::Parser parser_;
};

TEST_F(StorageTests, CanGetPackageView) {
  ASSERT_NO_THROW(storage_->GetPackageView("test_package"));
}

TEST_F(StorageTests, CanGetDirectoryView) {
  std::filesystem::path dir_path{"."};
  storage_->GetDirectoryView(dir_path);
  ASSERT_NO_THROW(storage_->GetDirectoryView("."));
}

TEST_F(StorageTests, MethodGetDirectroyViewThrowsExceptionIfGivenDirectoryPathIsInvalid) {
  std::filesystem::path incorrect_path{"this/path/does/not/exist"};
  ASSERT_THROW(storage_->GetDirectoryView(incorrect_path), std::runtime_error);
}

TEST_F(StorageTests, MethodGetPackageViewThrowsExceptionIfGivenPackageNameDoesNotExist) {
  std::string package_name{"invalid_package_name"};
  ASSERT_THROW(storage_->GetPackageView(package_name), std::runtime_error);
}

}  // namespace tests