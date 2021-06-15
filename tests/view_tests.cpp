#include <gtest/gtest.h>

#include <protobuf_parser/view/view.hpp>
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

TEST_F(StorageTests, CanIterateOverPackageMessages) {
  auto view = storage_->GetPackageView("test_package");
  std::size_t messages_count = 0;
  for (auto& message : view) {
    ++messages_count;
  }
  ASSERT_EQ(messages_count, 3);
}

TEST_F(StorageTests, CanIterateOverDirectroryMessage) {
  auto view = storage_->GetDirectoryView(".");
  std::size_t messages_count = 0;
  for (auto& message : view) {
    ++messages_count;
  }
  ASSERT_EQ(messages_count, 3);
}

}  // namespace tests