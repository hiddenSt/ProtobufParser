#ifndef PROTOBUF_PARSER__PARSE_ELEMENT_HPP_
#define PROTOBUF_PARSER__PARSE_ELEMENT_HPP_

#include <cstdint>

namespace protobuf_parser {

class ParseElement {
 public:
  ParseElement();
  ParseElement(const ParseElement& other);

  std::size_t GetId() const noexcept;
  void SetId(std::size_t id);

 private:
  std::size_t id_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER__PARSE_ELEMENT_HPP_
