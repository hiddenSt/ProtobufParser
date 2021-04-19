#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>


namespace tests {

class ParserTests : public ::testing::Test {
 protected:
  void SetUp() override {
    root_path_ = new std::filesystem::path{path_to_tests_proto_directory_};
  }

  std::string path_to_tests_proto_directory_ = "../../tests";
  std::filesystem::path* root_path_;
};

TEST_F(ParserTests, CanCreateProtobufParser) {
  ASSERT_NO_THROW(protobuf_parser::Parser{*root_path_});
}

TEST_F(ParserTests, CanGetStorage) {
  protobuf_parser::Parser parser{*root_path_};
  ASSERT_NO_THROW(parser.GetStorage());
}

}  // namespace tests