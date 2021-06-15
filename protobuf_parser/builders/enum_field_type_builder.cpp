#include "enum_field_type_builder.hpp"

namespace protobuf_parser {
namespace builders {

EnumFieldTypeBuilder::EnumFieldTypeBuilder(const std::string& type_name, const std::string& name,
                                           std::size_t number, bool optional, bool repeated)
    : enum_field_(type_name, name, number, optional, repeated) {
}

void EnumFieldTypeBuilder::SetUpParentMessageTypeId(std::size_t id) {
  enum_field_.enum_type_id_ = id;
}

EnumField& EnumFieldTypeBuilder::GetEnumFieldType() {
  return enum_field_;
}

}
}