#include "message.hpp"

namespace protobuf_parser {

Package* Message::GetPackage() const noexcept {
  return file_->GetPackage();
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

bool Message::operator==(const Message& other) {
  if (name_ != other.name_) {
    return false;
  }

  if (file_ != other.file_) {
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

const std::vector<Field>& Message::GetFields() const {
  return fields_;
}

const std::vector<Message>& Message::GetNestedMessages() const {
  return nested_messages_;
}


const std::vector<std::string>& Message::GetReservedNames() const {
  return reserved_names_;
}

const std::vector<std::size_t>& Message::GetReservedNumbers() const {
  return reserved_numbers_;
}

Message::Message(Message&& other) noexcept :
      name_(std::move(other.name_)),
      parent_message_(other.parent_message_),
      nested_messages_(std::move(other.nested_messages_)),
      file_(other.file_),
      fields_(std::move(other.fields_)),
      reserved_numbers_(std::move(other.reserved_numbers_)),
      reserved_names_(std::move(other.reserved_names_)) {
  other.file_ = nullptr;
  other.parent_message_ = nullptr;
  for (auto& nested_message: nested_messages_) {
    nested_message.parent_message_ = this;
  }
}

}  // namespace protobuf_parser