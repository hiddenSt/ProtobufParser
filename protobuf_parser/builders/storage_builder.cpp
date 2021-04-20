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

const Storage& StorageBuilder::GetStorage() const noexcept {
  return storage_;
}

void StorageBuilder::SetUpPackagesParents() {
  std::sort(package_builders_.begin(),package_builders_.end(),
            [](const PackageBuilder& a, const PackageBuilder& b) {
              return a.GetName() <= b.GetName();
  });

  // TODO: 
}

}
}