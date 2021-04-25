#include "message_field.hpp"

namespace protobuf_parser {

MessageField::MessageField(const std::string& type_name, const std::string& name,
                           std::size_t number, bool optional, bool repeated)
    : Field(name, type_name, number, optional, repeated) {
}

bool MessageField::IsMessageType() const noexcept {
  return true;
}

}  // namespace protobuf_parser
