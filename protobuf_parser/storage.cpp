#include "storage.hpp"

namespace protobuf_parser {

Storage::Storage(Storage&& other) noexcept
    : messages_(std::move(other.messages_)),
      files_(std::move(other.files_)),
      packages_(std::move(other.packages_)),
      directories_(std::move(other.directories_)) {
}

Storage& Storage::operator=(Storage&& other) noexcept {
  messages_ = std::move(other.messages_);
  packages_ = std::move(other.packages_);
  directories_ = std::move(other.directories_);
  files_ = std::move(other.files_);
  enums_ = std::move(other.enums_);
  return *this;
}

view::View<Directory> Storage::GetDirectoryView(const std::filesystem::path& directory_path) {
  Directory* root_dir = nullptr;
  for (auto& dir : directories_) {
    if (dir.GetPath() == directory_path) {
      root_dir = &dir;
    }
  }
  if (root_dir == nullptr) {
    throw std::runtime_error{"No such directory."};
  }
  return view::View<Directory>(root_dir, this);
}

view::View<Package> Storage::GetPackageView(const std::string& package_name) {
  Package* root_package = nullptr;
  for (auto& package : packages_) {
    if (package.GetName() == package_name) {
      root_package = &package;
    }
  }
  if (root_package == nullptr) {
    throw std::runtime_error{"Given package does not exist."};
  }
  return view::View<Package>(root_package, this);
}

}  // namespace protobuf_parser