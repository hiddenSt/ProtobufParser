#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_

#include <protobuf_parser/elements/fields/field.hpp>

namespace protobuf_parser {

class BuiltinField : public Field {
 public:
  explicit BuiltinField(const std::string& type_name, const std::string& name, std::size_t number,
                        bool optional, bool repeated);
  BuiltinField() = delete;

  bool IsBuiltinType() const noexcept override;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENTS_FIELDS_BUILTIN_FIELD_HPP_