#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_

namespace protobuf_parser {
namespace serializers {
class Serializer {
 public:
  virtual void AddObject();
  virtual void AddArray();
};
}  // namespace serializers
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_SERIALIZERS_SERIALIZER_HPP_
