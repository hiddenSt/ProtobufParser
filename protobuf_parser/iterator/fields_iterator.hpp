#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_

#include <protobuf_parser/field.hpp>

namespace protobuf_parser {
namespace iterator {

class FieldsIterator {
 public:
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual const Field& CurrentField() = 0;
};

}  // namespace iterator
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_ITERATOR_FIELDS_ITERATOR_HPP_
