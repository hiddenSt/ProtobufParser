#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/parser.hpp>

namespace tests {

TEST(ParserTests, CanCreateParser) {
  std::filesystem::path protos_path{"../../tests"};
  ASSERT_NO_THROW(protobuf_parser::Parser{protos_path});
}

TEST(ParserTests, CanCallParse) {
  std::filesystem::path protos_path{"../../tests"};
  protobuf_parser::Parser parser{protos_path};
  ASSERT_NO_THROW(parser.Parse());
}

TEST(ParserTests, CanGetStorage) {
  std::filesystem::path protos_path{"../../tests"};
  protobuf_parser::Parser parser{protos_path};
  parser.Parse();
  auto storage = std::move(parser.GetStorage());
  int a = 1;
  ++a;
}

}  // namespace tests