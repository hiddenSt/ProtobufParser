#include "message_builder.hpp"

#include <queue>

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
const std::string& MessageBuilder::GetName() const {
  return message_.GetName();
}

void MessageBuilder::SetUpFileName(const std::string& file_name) {
  file_name_ = file_name;
}

const std::string& MessageBuilder::GetFileName() {
  return file_name_;
}

void MessageBuilder::AddFile(File* file) noexcept {
  message_.file_ = file;
  std::queue<Message*> messages_queue;
  for (auto& message : message_.nested_messages_) {
    messages_queue.emplace(&message);
  }
  while (!messages_queue.empty()) {
    auto* message = messages_queue.front();
    messages_queue.pop();
    message->file_ = message_.file_;
    for (auto& nested : message->nested_messages_) {
      messages_queue.emplace(&nested);
    }
  }
}

MessageBuilder::MessageBuilder(MessageBuilder&& other) noexcept
    : message_(std::move(other.message_)), file_name_(std::move(other.file_name_)) {
}

}  // namespace builders
}  // namespace protobuf_parser