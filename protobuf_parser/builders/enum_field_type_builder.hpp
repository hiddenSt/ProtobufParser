#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_FIELD_TYPE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_FIELD_TYPE_BUILDER_HPP_

#include <protobuf_parser/elements/fields/enum_field.hpp>

namespace protobuf_parser {
namespace builders {

class EnumFieldTypeBuilder {
 public:
  EnumFieldTypeBuilder(const std::string& type_name, const std::string& name, std::size_t number,
                       bool optional, bool repeated);
  void SetUpParentMessageTypeId(std::size_t id);

  EnumField& GetEnumFieldType();

 private:
  EnumField enum_field_;
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_FIELD_TYPE_BUILDER_HPP_
