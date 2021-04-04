#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_

#include <proto_buff_parser/field.hpp>

namespace proto_buff_parser {
namespace iterator {

class FieldsIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual const Field& CurrentField() = 0;
};

}  // namespace iterator
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_
