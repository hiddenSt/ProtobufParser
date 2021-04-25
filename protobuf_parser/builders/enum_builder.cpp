#include "enum_builder.hpp"

namespace protobuf_parser {
namespace builders {

void EnumBuilder::SetUpName(const std::string& name) {
  enum_.name_ = name;
}

void EnumBuilder::SetUpParentMessage(Message* message) {
  enum_.parent_message_ = message;
}

void EnumBuilder::SetUpFile(File* file) {
  enum_.file_ = file;
}

void EnumBuilder::AddValue(const std::string& name, std::size_t number) {
  enum_.values_.insert(std::make_pair(number, name));
}

void EnumBuilder::SetUpFilePath(const std::filesystem::path& path) {
  file_path_ = file_path_;
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

}
}
