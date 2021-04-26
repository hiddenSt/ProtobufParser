#include "element.hpp"

namespace protobuf_parser {
std::size_t Element::elements_count_ = 0;

Element::Element() : id_(++elements_count_) {
}

const std::size_t Element::GetId() const noexcept {
  return id_;
}

Element::Element(Element&& other) noexcept : id_(other.id_) {
  other.id_ = -1;
}

}  // namespace protobuf_parser
