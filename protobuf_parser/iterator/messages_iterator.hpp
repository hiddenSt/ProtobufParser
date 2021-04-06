#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_

#include <protobuf_parser/parse_elements/message.hpp>

namespace protobuf_parser {
namespace iterator {

class MessagesIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Message& CurrentMessage() = 0;
  virtual ~MessagesIterator() = 0;
};

}  // namespace iterator
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_MESSAGES_ITERATOR_HPP_
