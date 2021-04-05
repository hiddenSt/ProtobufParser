#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_

#include <protobuf_parser/field_type.hpp>

namespace protobuf_parser {

class EnumFieldType : public FieldType {
 public:
  const std::string& GetName() const override;

 private:
  std::string name_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ENUM_FIELD_TYPE_HPP_
