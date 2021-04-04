#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_

#include <proto_buff_parser/iterator/fields_iterator.hpp>

namespace proto_buff_parser {
namespace container {

class FieldsContainer {
 public:
  virtual void AddField(const Field& field) = 0;
  virtual iterator::FieldsIterator& GetFieldsIterator() = 0;
};

}  // namespace container
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_FIELDS_CONTAINER_HPP_
