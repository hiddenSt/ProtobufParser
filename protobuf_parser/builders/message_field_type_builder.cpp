#include "message_field_type_builder.hpp"

namespace protobuf_parser {
namespace builders {

MessageFieldTypeBuilder::MessageFieldTypeBuilder(const std::string& type_name,
                                                 const std::string& name, std::size_t number,
                                                 bool optional, bool repeated)
    : message_field_(type_name, name, number, optional, repeated) {
}

MessageField& MessageFieldTypeBuilder::GetMessageField() {
  return message_field_;
}

void MessageFieldTypeBuilder::SetUpMessageTypeId(std::size_t id) {
  message_field_.message_type_id_ = id;
}
}
}