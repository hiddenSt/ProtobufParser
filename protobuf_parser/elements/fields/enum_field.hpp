#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class EnumField : public Field {
 public:
  EnumField(const std::string& type_name, const std::string& name, std::size_t number,
            bool optional, bool repeated);

  bool IsEnumType() const noexcept override;

  void Serialize(serializers::Serializer& serializer) const override;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_
