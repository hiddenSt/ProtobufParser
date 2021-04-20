#include "message_builder.hpp"

namespace protobuf_parser {
namespace builders {

void MessageBuilder::SetUpName(const std::string& name) noexcept {
  message_.name_ = name;
}

void MessageBuilder::SetUpParent(Message* parent) noexcept {
  message_.parent_message_ = parent;
}

void MessageBuilder::SetUpFile(File* file) noexcept {
  message_.file_ = file;
}

void MessageBuilder::AddNestedMessage(Message&& message) {
  message_.nested_messages_.emplace_back(std::move(message));
  message_.nested_messages_[message_.nested_messages_.size() - 1].parent_message_ = &message_;
}

void MessageBuilder::AddFiled(const Field& field) {
  message_.fields_.push_back(field);
}

void MessageBuilder::AddReservedName(const std::string& name) {
  message_.reserved_names_.push_back(name);
}

void MessageBuilder::AddReservedNumber(std::size_t number) {
  message_.reserved_numbers_.push_back(number);
}

Message& MessageBuilder::GetMessage() {
  return message_;
}

}
}