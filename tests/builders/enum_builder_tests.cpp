#include <gtest/gtest.h>

#include <protobuf_parser/builders/enum_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>

namespace tests {

TEST(EnumBuilderTests, CanCreateBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::EnumBuilder{});
}

TEST(EnumBuilderTests, CanSetUpEnumName) {
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  ASSERT_NO_THROW(builder.SetUpName(enum_name));
}

TEST(EnumBuilderTests, CanGetEnum) {
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  ASSERT_NO_THROW(builder.GetEnum());
}

TEST(EnumBuilderTests, MethodGetEnumReturnsCorrectEnum) {
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  auto an_enum = std::move(builder.GetEnum());
  ASSERT_EQ(an_enum.GetName(), enum_name);
}

TEST(EnumBuilderTests, CanSetUpFile) {
  std::filesystem::path file_path{"FilePath"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::FileBuilder file_builder{};
  protobuf_parser::builders::EnumBuilder enum_builder{};
  file_builder.SetUpPath(file_path);
  auto file = std::move(file_builder.GetFile());

  enum_builder.SetUpName(enum_name);

  ASSERT_NO_THROW(enum_builder.SetUpFile(&file));
}

TEST(EnumBuilderTests, CanSetUpFilePath) {
  std::filesystem::path file_path{"FilePath"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder enum_builder{};
  enum_builder.SetUpName(enum_name);
  ASSERT_NO_THROW(enum_builder.SetUpFilePath(file_path));
}

TEST(EnumBuilderTests, CanGetFilePath) {
  std::filesystem::path file_path{"FilePath"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder enum_builder{};
  enum_builder.SetUpName(enum_name);
  enum_builder.SetUpFilePath(file_path);
  ASSERT_NO_THROW(enum_builder.GetFilePath());
}

TEST(EnumBuilderTests, MethodGetFilePathReturnsCorrectPath) {
  std::filesystem::path file_path{"FilePath"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder enum_builder{};
  enum_builder.SetUpName(enum_name);
  enum_builder.SetUpFilePath(file_path);
  ASSERT_EQ(enum_builder.GetFilePath(), file_path);
}

TEST(EnumBuilderTests, CanSetUpMessageName) {
  std::string message_name{"MessageName"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  ASSERT_NO_THROW(builder.SetUpMessageName(message_name));
}

TEST(EnumBuilderTests, CanGetMessageName) {
  std::string message_name{"MessageName"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  builder.SetUpMessageName(message_name);
  ASSERT_NO_THROW(builder.GetMessageName());
}

TEST(EnumBuilderTests, MethodGetMessageNameReturnsCorrectName) {
  std::string message_name{"MessageName"};
  std::string enum_name{"EnumName"};
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  builder.SetUpMessageName(message_name);
  ASSERT_EQ(builder.GetMessageName(), message_name);
}

TEST(EnumBuilderTests, CanAddValue) {
  std::string enum_name{"EnumName"};
  std::string value_name{"ValueName"};
  std::size_t value_number = 1;
  protobuf_parser::builders::EnumBuilder builder{};
  builder.SetUpName(enum_name);
  ASSERT_NO_THROW(builder.AddValue(value_name, value_number));
}

}  // namespace tests