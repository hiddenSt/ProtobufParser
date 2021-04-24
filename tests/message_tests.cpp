#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/builders/message_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

class MessageTests : public ::testing::Test {
 protected:
  void SetUp() override {
    SetUpTestData();
    SetUpDirectories();
    SetUpPackages();
    SetUpFile();
    SetUpMessage();
  }

  void TearDown() override {

  }

  void SetUpDirectories() {

  }

  void SetUpPackages() {

  }

  void SetUpFile() {

  }

  void SetUpMessage() {

  }

  void SetUpTestData() {
    
  }

  protobuf_parser::Directory outer_dir_;
  protobuf_parser::Directory inner_dir_;
  protobuf_parser::Package parent_package_;
  protobuf_parser::Package child_package_;
  protobuf_parser::File file_;
  protobuf_parser::Message message_;

  std::filesystem::path outer_dir_path_;
  std::filesystem::path inner_dir_path_;
  std::string parent_package_name_;
  std::string child_package_name_;
  std::string file_name_;
  std::string message_name_;
};

TEST(MessageTests, CanCreateMessage) {

}

TEST(MessageTests, CanGetNestedMessages) {
}

TEST(MessageTests, CanGetParentMessage) {
}

TEST(MessageTests, CanGetFile) {
}

TEST(MessageTests, CanGetDirectory) {
}

TEST(MessageTests, CanGetPackage) {
}

TEST(MessageTests, CanGetMessageName) {
}

TEST(MessageTests, CanGetFields) {
}

}  // namespace tests