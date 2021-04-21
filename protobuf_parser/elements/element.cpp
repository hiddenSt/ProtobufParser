#include "element.hpp"

namespace protobuf_parser {
std::size_t Element::elements_count_ = 0;

Element::Element() : id_(++elements_count_) {
}

const std::size_t Element::GetId() const noexcept {
  return id_;
}

}  // namespace protobuf_parser
