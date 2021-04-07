#include "message.hpp"

namespace protobuf_parser {

Message::Message()
    : name_(), package_(nullptr), file_(nullptr), parent_message_(nullptr), fields_() {
}

Message::Message(const std::string& name, File* file, Package* package, Message* parent_message)
    : name_(name), file_(file), package_(package), parent_message_(parent_message) {
}

Message::Message(const std::string& name, File* file, Package* package)
    : name_(name), file_(file), package_(package), parent_message_(nullptr) {
}

Message::Message(const Message& other)
    : name_(other.name_),
      parent_message_(other.parent_message_),
      file_(other.file_),
      package_(other.package_),
      fields_(other.fields_) {
}

Package* Message::GetPackage() const noexcept {
  return package_;
}

File* Message::GetFile() const noexcept {
  return file_;
}

Message* Message::GetParentMessage() const noexcept {
  return parent_message_;
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

bool Message::operator==(const Message& other) {
  if (name_ != other.name_) {
    return false;
  }

  if (file_ != other.file_) {
    return false;
  }

  if (package_ != other.package_) {
    return false;
  }

  if (parent_message_ != other.parent_message_) {
    return false;
  }

  return true;
}

bool Message::operator!=(const Message& other) {
  return !(*this == other);
}

Directory* Message::GetDirectory() {
  return file_->GetDirectory();
}
void Message::AddField(const Field& field) {
  fields_.push_back(field);
}

const std::vector<Field>& Message::GetFields() const {
  return fields_;
}

const std::vector<Message*>& Message::GetNestedMessages() const {
  return nested_messages_;
}

void Message::AddNestedMessage(Message* message) {
  nested_messages_.push_back(message);
}

}  // namespace protobuf_parser