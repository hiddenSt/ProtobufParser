#include <gtest/gtest.h>

#include <filesystem>

#include <protobuf_parser/storage.hpp>

#include <google/protobuf/compiler/importer.h>
#include <protobuf_parser/parser.hpp>

namespace tests {

TEST(StorageTests, CanCreateStorage) {

}

TEST(StorageTests, CanGetPackageView) {
  std::filesystem::path protos_path{"../../tests/protos"};
  protobuf_parser::Parser parser{protos_path};
  parser.Parse();
  auto storage = std::move(parser.GetStorage());
  auto view = storage.GetPackageView("test_package");
  ASSERT_NO_THROW(storage.GetPackageView("test_package"));
}

TEST(StorageTests, CanGetDirectoryView) {
}

}  // namespace tests