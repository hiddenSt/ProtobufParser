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
  ASSERT_NO_THROW(
      protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer>{*root_path_});
}

TEST_F(ParserTests, CanGetSerializedMessageFromDirectory) {
  std::string directory_path{"protos"};
  protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{
      *root_path_};
  ASSERT_NO_THROW(protobuf_parser.SerializeDirectory(directory_path));
}

TEST_F(ParserTests, CanGetSerializedMessageFromPackage) {
  std::string package_name{"test_package"};
  protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{
      *root_path_};
  ASSERT_NO_THROW(protobuf_parser.SerializePackage(package_name));
}

TEST_F(ParserTests, ThrowsExceptionIfGivenDirectoryDoesNotExists) {
  protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{*root_path_};
  std::string no_existing_directory_name{"NoName"};
  std::filesystem::path no_existing_path{no_existing_directory_name};
  ASSERT_THROW(protobuf_parser.SerializeDirectory(no_existing_path), std::runtime_error);
}

TEST_F(ParserTests, ThrowsExceptionIfGivenPackageDoesNotExists) {
  protobuf_parser::Parser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{*root_path_};
  std::string no_existing_package_name{"no.exists"};
  ASSERT_THROW(protobuf_parser.SerializePackage(no_existing_package_name), std::runtime_error);
}

}  // namespace tests