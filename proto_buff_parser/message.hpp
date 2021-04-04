#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_

#include <string>
#include <vector>

#include <proto_buff_parser/field.hpp>

namespace proto_buff_parser {

class Message {
 public:
  Message();

 private:
  std::string name_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_MESSAGE_HPP_
