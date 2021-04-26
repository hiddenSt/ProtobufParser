#include <gtest/gtest.h>

#include <protobuf_parser/view/view.hpp>
#include <protobuf_parser/parser.hpp>

namespace tests {

class StorageTests : public ::testing::Test {
 protected:
  StorageTests() :  parser_(std::filesystem::path("../../tests/protos")) {
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

}

TEST_F(StorageTests, CanIterateOverDirectroryMessage) {

}

}