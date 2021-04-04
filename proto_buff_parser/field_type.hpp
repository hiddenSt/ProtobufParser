#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_TYPE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_TYPE_HPP_

#include <string>

namespace proto_buff_parser {

class FieldType {
 public:
  virtual const std::string& GetName() = 0;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_FIELD_TYPE_HPP_
