#include "builtin_field.hpp"

namespace protobuf_parser {

bool Builtin::IsBuiltinType() const noexcept {
  return true;
}

const std::string& Builtin::GetType() const {
  return type_name_;
}
Builtin::Builtin(const std::string& name, std::size_t number, bool optional, bool repeated,
                 const std::string& type_name)
    : Field(name, number, optional, repeated), type_name_(type_name) {
}

}