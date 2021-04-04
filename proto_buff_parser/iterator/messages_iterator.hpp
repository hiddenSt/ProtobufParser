#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_

#include <proto_buff_parser/message.hpp>

namespace proto_buff_parser {
namespace iterator {

class MessagesIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Message& CurrentMessage() = 0;
};

}  // namespace iterator
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_
