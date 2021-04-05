#include "message.hpp"

namespace protobuf_parser {

Message::Message(const std::string& name, const File& file, const Package& package,
                 const Message* const parent_message)
    : name_(name),
      file_(file),
      package_(package),
      parent_message_(parent_message) {
}

Message::Message(const std::string& name, const File& file, const Package& package)
    : name_(name),
      file_(file),
      package_(package),
      parent_message_(nullptr) {
}

const Package& Message::GetPackage() const noexcept {
  return package_;
}

const File& Message::GetFile() const noexcept {
  return file_;
}

const Message& Message::GetParentMessage() const noexcept {
  return *parent_message_;
}

const std::string& Message::GetName() const {
  return name_;
}

}  // namespace protobuf_parser