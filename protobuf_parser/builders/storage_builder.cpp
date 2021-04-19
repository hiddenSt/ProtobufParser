#include "storage_builder.hpp"

namespace protobuf_parser {
namespace builders {

void StorageBuilder::AddDirectories(const std::set<std::string>& directories) {
  for (auto& directory_name: directories) {
    storage_.directories_.emplace_back(directory_name);
  }
}

void StorageBuilder::AddPackages(const std::set<std::string>& packages) {
  for (auto& package_name: packages) {
    storage_.packages_.emplace_back(package_name);
  }
}

}
}