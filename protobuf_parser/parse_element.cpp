#include "parse_element.hpp"

namespace protobuf_parser {

std::size_t ParseElement::elements_count_ = 0;

ParseElement::ParseElement() {
  id_ = ++elements_count_;
}
std::size_t ParseElement::GetId() const noexcept {
  return id_;
}
}  // namespace protobuf_parser