#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_

#include <string>

namespace protobuf_parser {
namespace serializers {
class Serializer {
 public:
  virtual void AddField(const std::string& field_name, const std::string& field_value);
};
}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_
