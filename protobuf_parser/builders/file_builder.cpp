#include "file_builder.hpp"

namespace protobuf_parser {
namespace builders {

void FileBuilder::SetUpPath(const std::filesystem::path& file_path) noexcept {
  file_.path_ = file_path;
}

void FileBuilder::SetUpDirectory(Directory* directory) noexcept {
  file_.directory_ = directory;
}

void FileBuilder::SetUpPackage(Package* package) noexcept {
  file_.package_ = package;
}

File& FileBuilder::GetFile() {
  return file_;
}

const std::filesystem::path& FileBuilder::GetPath() const {
  return file_.path_;
}

void FileBuilder::SetUpPackageName(const std::string& package_name) {
  package_name_ = package_name;
}

const std::string& FileBuilder::GetPackageName() const {
  return package_name_;
}

FileBuilder::FileBuilder(FileBuilder&& other) noexcept
    : package_name_(std::move(other.package_name_)), file_(std::move(other.file_)) {
}

}  // namespace builders
}  // namespace protobuf_parser