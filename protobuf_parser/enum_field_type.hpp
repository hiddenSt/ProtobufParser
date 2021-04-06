#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_

#include <protobuf_parser/field_type.hpp>
#include <protobuf_parser/parse_elements/enum.hpp>

namespace protobuf_parser {

template <std::size_t size>
class EnumFieldType : public FieldType {
 public:
  explicit EnumFieldType(const Enum<size>& an_enum);

  const std::string& GetName() const override;

 private:
  Enum<size>& an_enum_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_
