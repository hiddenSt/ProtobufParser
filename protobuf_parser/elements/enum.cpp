#include "enum.hpp"

namespace protobuf_parser {

bool Enum::HasParentMessage() const noexcept {
  return parent_message_ != nullptr;
}

const Message& Enum::GetParentMessage() const {
  return *parent_message_;
}

const File& Enum::GetFile() const {
  return *file_;
}

const std::string& Enum::GetName() const {
  return name_;
}

const std::map<std::size_t, std::string>& Enum::GetValues() const {
  return values_;
}
}
