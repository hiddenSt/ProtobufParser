#include "field.hpp"

namespace proto_buff_parser {



const std::string& Field::GetName() const {
  return name_;
}

const std::string& Field::GetType() const {
  return type_;
}

std::size_t Field::GetNumber() const {
  return number_;
}

}  // namespace proto_buff_parser
