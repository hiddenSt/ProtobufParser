#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {
namespace builders {
class EnumFieldTypeBuilder;
}

class EnumField : public Field {
 public:
  EnumField(const std::string& type_name, const std::string& name, std::size_t number,
            bool optional, bool repeated);

  bool IsEnumType() const noexcept override;

  std::map<std::string, std::string> Serialize() const override;

 private:
  friend class builders::EnumFieldTypeBuilder;

  std::size_t enum_type_id_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_ENUM_FIELD_HPP_
