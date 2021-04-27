#include "enum_builder.hpp"

namespace protobuf_parser {
namespace builders {

void EnumBuilder::SetUpName(const std::string& name) {
  enum_.name_ = name;
}

void EnumBuilder::SetUpFile(File* file) {
  enum_.file_ = file;
}

void EnumBuilder::AddValue(const std::string& name, std::size_t number) {
  enum_.values_.insert(std::make_pair(number, name));
}

void EnumBuilder::SetUpFilePath(const std::filesystem::path& path) {
  file_path_ = path;
}

void EnumBuilder::SetUpMessageName(const std::string& name) {
  message_name_ = name;
}

const std::string& EnumBuilder::GetMessageName() const {
  return message_name_;
}

const std::filesystem::path& EnumBuilder::GetFilePath() const {
  return file_path_;
}

Enum& EnumBuilder::GetEnum() {
  return enum_;
}

EnumBuilder::EnumBuilder(EnumBuilder&& other) noexcept
    : message_name_(std::move(other.message_name_)),
      enum_(std::move(other.enum_)),
      file_path_(std::move(other.file_path_)) {
}

EnumBuilder& EnumBuilder::operator=(EnumBuilder&& other) noexcept {
  message_name_ = std::move(other.message_name_);
  enum_ = std::move(other.enum_);
  file_path_ = std::move(file_path_);
  return *this;
}

}  // namespace builders
}  // namespace protobuf_parser
