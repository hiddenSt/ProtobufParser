#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_ENUM_FIELD_TYPE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_ENUM_FIELD_TYPE_HPP_

#include <proto_buff_parser/field_type.hpp>

namespace proto_buff_parser {

class EnumFieldType : public FieldType {
 public:
  const std::string& GetName() override;

 private:
  std::string name_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_ENUM_FIELD_TYPE_HPP_
