#include "storage_builder.hpp"

namespace protobuf_parser {
namespace builders {

void StorageBuilder::AddDirectoryBuilder(DirectoryBuilder* directory_builder) {
  directory_builders_.push_back(directory_builder);
}

void StorageBuilder::AddPackageBuilder(PackageBuilder* package_builder) {
  package_builders_.push_back(package_builder);
}

void StorageBuilder::AddFileBuilder(FileBuilder* file_builder) {
  file_builders_.push_back(file_builder);
}

void StorageBuilder::AddMessageBuilder(MessageBuilder* message_builder) {
  message_builders_.push_back(message_builder);
}

const Storage& StorageBuilder::GetStorage() {
  BuildDirectories();
  BuildPackages();
  BuildFiles();
  BuildMessages();
  return storage_;
}

Package* StorageBuilder::FindParentForPackage(const std::string& package_name) {
  for (auto& package: storage_.packages_) {
    if (package_name.find(package.GetName() + ".") == 0) {
      std::size_t i = 0;
      while (package.GetName()[i] == package_name[i]) {
        ++i;
      }
      ++i;
      while (i < package_name.size()) {
        if (package_name[i] == '.') {
          continue;
        }
      }
      return &package;
    }
  }
  return nullptr;
}

Directory* StorageBuilder::FindParentForDirectory(const std::string& directory_name) {
  for (auto& directory: storage_.directories_) {
    if (directory_name.find(directory.GetName() + "/") == 0) {
      std::size_t i = 0;
      while (directory.GetName()[i] == directory_name[i]) {
        ++i;
      }
      ++i;
      while (i < directory_name.size()) {
        if (directory_name[i] == '/') {
          continue;
        }
      }
      return &directory;
    }
  }
  return nullptr;
}

}
}