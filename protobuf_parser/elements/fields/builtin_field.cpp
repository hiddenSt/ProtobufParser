#include "builtin_field.hpp"

namespace protobuf_parser {

Builtin::Builtin(const std::string& type_name, const std::string& name, std::size_t number, bool optional, bool repeated)
    : Field(name, type_name, number, optional, repeated) {
}

bool Builtin::IsBuiltinType() const noexcept {
  return true;
}

}