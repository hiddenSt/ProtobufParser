#include <gtest/gtest.h>

#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/builders/message_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>

namespace tests {

protobuf_parser::Message GetMessage(const std::string& message_name) {
  std::string dir_name{"hello_world_dir"};
  std::string package_name{"HelloWorld"};
  std::string file_name{dir_name + "/Hello world"};

  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  protobuf_parser::builders::PackageBuilder package_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};
  protobuf_parser::builders::MessageBuilder message_builder{};

  directory_builder.SetUpName(dir_name);
  package_builder.SetUpName(package_name);
  file_builder.SetUpName(file_name);
  message_builder.SetUpName(message_name);

  auto directory = std::move(directory_builder.GetDirectory());
  auto package = std::move(package_builder.GetPackage());
  file_builder.SetUpDirectory(&directory);
  file_builder.SetUpPackage(&package);
  auto file = std::move(file_builder.GetFile());

  message_builder.SetUpFile(&file);
  return std::move(message_builder.GetMessage());
}

TEST(MessageTests, CanCreateMessage) {
  std::string message_name{"CoolName"};

  auto message = GetMessage(message_name);

  ASSERT_EQ(message.GetName(), message_name);
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