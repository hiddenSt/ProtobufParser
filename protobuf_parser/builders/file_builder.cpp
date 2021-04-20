#include "file_builder.hpp"

namespace protobuf_parser {
namespace builders {

void FileBuilder::SetUpName(const std::string& name) noexcept {
  file_.name_ = name;
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

const std::string& FileBuilder::GetName() const {
  return file_.GetName();
}

}
}