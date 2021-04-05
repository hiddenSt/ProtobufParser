#ifndef PROTOBUF_PARSER__PARSE_ELEMENT_HPP_
#define PROTOBUF_PARSER__PARSE_ELEMENT_HPP_

#include <cstdint>

namespace protobuf_parser {

class ParseElement {
 public:
  ParseElement();

  std::size_t GetId() const noexcept;

 private:
  static std::size_t elements_count_;
  std::size_t id_;
};

}

#endif  // PROTOBUF_PARSER__PARSE_ELEMENT_HPP_
