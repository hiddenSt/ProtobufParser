#include "message.hpp"

namespace protobuf_parser {

Message::Message(const std::string& name, const File& file, const Package& package,
                 container::FieldsContainer& fields_container, const Message* const parent_message)
    : name_(name),
      file_(file),
      package_(package),
      fields_container_(fields_container),
      parent_message_(parent_message) {
}

Message::Message(const std::string& name, const File& file, const Package& package,
                 container::FieldsContainer& fields_container)
    : name_(name),
      file_(file),
      package_(package),
      fields_container_(fields_container),
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

iterator::FieldsIterator& Message::GetFieldsIterator() {
  return fields_container_.GetFieldsIterator();
}

const std::string& Message::GetName() const {
  return name_;
}

}  // namespace protobuf_parser