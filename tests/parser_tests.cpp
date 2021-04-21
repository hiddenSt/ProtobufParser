#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/parser.hpp>

namespace tests {

TEST(ParserTests, CanCreateParser) {
  std::filesystem::path protos_path{"../../tests"};
  ASSERT_NO_THROW(protobuf_parser::Parser{protos_path});
}

}  // namespace tests