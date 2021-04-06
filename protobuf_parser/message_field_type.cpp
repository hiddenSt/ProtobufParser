#include "message_field_type.hpp"

namespace protobuf_parser {

MessageFieldType::MessageFieldType(const Message& message) : message_(message) {
}

const std::string& MessageFieldType::GetTypeName() const {
  return message_.GetName();
}

const Message& MessageFieldType::GetMessage() const {
  return message_;
}

}  // namespace protobuf_parser