#include "parse_element.hpp"

namespace protobuf_parser {

ParseElement::ParseElement() {
}

std::size_t ParseElement::GetId() const noexcept {
  return id_;
}

ParseElement::ParseElement(const ParseElement& other) : id_(other.id_) {
}

void ParseElement::SetId(std::size_t id) {
  id_ = id;
}

}  // namespace protobuf_parser