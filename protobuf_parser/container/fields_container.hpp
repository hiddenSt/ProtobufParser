#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_

#include <protobuf_parser/iterator/fields_iterator.hpp>

namespace protobuf_parser {
namespace container {

class FieldsContainer {
 public:
  virtual void AddField(const Field& field) = 0;
  virtual iterator::FieldsIterator& GetFieldsIterator() = 0;
  virtual ~FieldsContainer() = 0;
};

}  // namespace container
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_
