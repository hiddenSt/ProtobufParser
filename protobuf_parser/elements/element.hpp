#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_

#include <cstdint>

namespace protobuf_parser {

class Element {
 public:
  Element();

  const std::size_t GetId() const noexcept;

 private:
  const std::size_t id_;
  static std::size_t elements_count_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ELEMENT_HPP_
