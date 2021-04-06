#include "message.hpp"

namespace protobuf_parser {

Message::Message(const std::string& name, File* file, Package* package, Message* parent_message)
    : name_(name), file_(file), package_(package), parent_message_(parent_message) {
}

Message::Message(const std::string& name, File* file, Package* package)
    : name_(name), file_(file), package_(package), parent_message_(nullptr) {
}

Message::Message(const Message& other) : name_(other.name_), parent_message_(other.parent_message_), file_(other.file_), package_(other.package_), fields_(other.fields_) {
}

const Package& Message::GetPackage() const noexcept {
  return *package_;
}

const File& Message::GetFile() const noexcept {
  return *file_;
}

const Message& Message::GetParentMessage() const noexcept {
  return *parent_message_;
}

const std::string& Message::GetName() const {
  return name_;
}

Message& Message::operator=(const Message& other) {
  name_ = other.name_;
  parent_message_ = other.parent_message_;
  file_ = other.file_;
  package_ = other.package_;
  fields_ = other.fields_;
  return *this;
}

}  // namespace protobuf_parser