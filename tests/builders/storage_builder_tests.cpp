#include <gtest/gtest.h>

#include <protobuf_parser/builders/storage_builder.hpp>

namespace test {

TEST(StorageBuilderTests, CanCreateBuilder) {
  ASSERT_NO_THROW(protobuf_parser::builders::StorageBuilder{});
}

TEST(StorageBuilderTests, CanAddMessage) {
  std::string directory_name{"dir_name"};
  std::string package_name{"package_name"};
  std::string file_name{"dir_name/file_name"};
  std::string message_name{"message_name"};
  protobuf_parser::builders::DirectoryBuilder directory_builder{};
  protobuf_parser::builders::PackageBuilder package_builder{};
  protobuf_parser::builders::FileBuilder file_builder{};
  protobuf_parser::builders::MessageBuilder message_builder{};
  directory_builder.SetUpName(directory_name);
  package_builder.SetUpName(package_name);
  file_builder.SetUpName(file_name);
  file_builder.SetUpPackageName(package_name);
  message_builder.SetUpName(message_name);
  message_builder.SetUpFileName(file_name);

  protobuf_parser::builders::StorageBuilder storage_builder{};
  storage_builder.AddDirectoryBuilder(&directory_builder);
  storage_builder.AddPackageBuilder(&package_builder);
  storage_builder.AddFileBuilder(&file_builder);
  storage_builder.AddMessageBuilder(&message_builder);
}

}  // namespace test
