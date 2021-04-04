#include "message_field_type.hpp"

namespace proto_buff_parser {

MessageFieldType::MessageFieldType(const std::string name, const Message& message)
    : name_(name), message_(message) {
}

const std::string& MessageFieldType::GetName() {
  return name_;
}

const Message& MessageFieldType::GetMessage() const {
  return message_;
}

}  // namespace proto_buff_parser