#include "message.hpp"

namespace protobuf_parser {

Message::Message() : parent_message_(nullptr), file_(nullptr) {
}

const Package& Message::GetPackage() const noexcept {
  return file_->GetPackage();
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

const Directory& Message::GetDirectory() const {
  return file_->GetDirectory();
}

const std::vector<Field*>& Message::GetFields() const {
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

Message::Message(Message&& other) noexcept
    : Element(std::move(other)),
      name_(std::move(other.name_)),
      parent_message_(other.parent_message_),
      nested_messages_(std::move(other.nested_messages_)),
      file_(other.file_),
      fields_(std::move(other.fields_)),
      reserved_numbers_(std::move(other.reserved_numbers_)),
      reserved_names_(std::move(other.reserved_names_)) {
  other.file_ = nullptr;
  other.parent_message_ = nullptr;
  for (auto& nested_message : nested_messages_) {
    nested_message.parent_message_ = this;
  }
}

std::map<std::string, std::string> Message::Serialize() const {
  std::map<std::string, std::string> serialized_message;
  serialized_message["id"] = std::to_string(this->GetId());
  serialized_message["name"] = name_;
  serialized_message["file_id"] = std::to_string(file_->GetId());
  if (parent_message_ != nullptr) {
    serialized_message["parent_message_id"] = std::to_string(parent_message_->GetId());
  }
  return serialized_message;
}

const std::vector<Enum>& Message::GetEnums() const {
  return enums_;
}

}  // namespace protobuf_parser