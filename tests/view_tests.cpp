#include <gtest/gtest.h>

#include <protobuf_parser/view/view.hpp>
#include <protobuf_parser/parser.hpp>

namespace tests {

class ViewTests : public ::testing::Test {
 protected:
  ViewTests() :  parser_(std::filesystem::path("../../tests/protos")) {
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

TEST_F(ViewTests, CanGetPackageView) {
  std::string package_name{"test_package"};
  ASSERT_NO_THROW(storage_->GetPackageView(package_name));
}

TEST_F(ViewTests, CanGetDirectoryView) {
  std::filesystem::path directory_path{"/"};
  ASSERT_NO_THROW(storage_->GetDirectoryView(directory_path));
}

TEST_F(ViewTests, CanIterateOverPackageMessages) {

}

TEST_F(ViewTests, CanIterateOverDirectroryMessage) {

}

}