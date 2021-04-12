#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/protobuf_parser.hpp>
#include <protobuf_parser/serializers/json_serializer.hpp>

namespace tests {
TEST(ProtobufParserTests, CanCreateProtobufParser) {
  std::string path_to_tests_proto_directory_ = "../../tests";
  std::filesystem::path root_path{path_to_tests_proto_directory_};
  ASSERT_NO_THROW(protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer>{root_path});
}

TEST(ProtobufParserTests, CanGetSerializedMessage) {
  std::string path_to_tests_proto_directory_ = "../../tests";
  std::filesystem::path root_path{path_to_tests_proto_directory_};
  protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{root_path};
  ASSERT_NO_THROW(protobuf_parser.SerializeDirectory("protos"));
}

TEST(ProtobufParserTests, ReturnsCorrectJson) {
  std::string path_to_tests_proto_directory_ = "../../tests";
  std::filesystem::path root_path{path_to_tests_proto_directory_};
  protobuf_parser::ProtobufParser<protobuf_parser::serializer::JsonSerializer> protobuf_parser{root_path};
  auto message = protobuf_parser.SerializeDirectory("protos");
  ASSERT_EQ(1, 2) << message;
}
}