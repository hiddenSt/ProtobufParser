#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/parser.hpp>
#include <protobuf_parser/parse_exception.hpp>

namespace tests {

TEST(ParserTests, CanCreateParser) {
  std::filesystem::path protos_path{"../../tests/protos"};
  ASSERT_NO_THROW(protobuf_parser::Parser{protos_path});
}

TEST(ParserTests, CanCallParse) {
  std::filesystem::path protos_path{"../../tests/protos"};
  protobuf_parser::Parser parser{protos_path};
  ASSERT_NO_THROW(parser.Parse());
}

TEST(ParserTests, CanGetStorage) {
  std::filesystem::path protos_path{"../../tests/protos"};
  protobuf_parser::Parser parser{protos_path};
  parser.Parse();
  ASSERT_NO_THROW(parser.GetStorage());
}

TEST(ParserTests, ThrowsExceptionIfGivenProtoFileHasSyntaxErrors) {
  std::filesystem::path protos_path{"../../tests/protos_with_errors"};
  ASSERT_THROW(protobuf_parser::Parser parser{protos_path}, protobuf_parser::ParseException);
}

}  // namespace tests