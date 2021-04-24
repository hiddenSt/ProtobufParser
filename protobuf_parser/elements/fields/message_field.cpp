#include "message_field.hpp"

namespace protobuf_parser {

MessageField::MessageField(const std::string& name, std::size_t number, bool optional,
                           bool repeated, const std::string& type_name)
    : Field(name, number, optional, repeated), type_name_(type_name) {
}

const std::string& MessageField::GetType() const {
  return type_name_;
}

bool MessageField::IsMessageType() const noexcept {
  return true;
}

}
