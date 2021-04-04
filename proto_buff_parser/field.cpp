#include "field.hpp"

namespace proto_buff_parser {

Field::Field(std::string name, const std::size_t number, std::string type, Message& message)
    : name_(std::move(name)), number_(number), type_(std::move(type)), message_(message) {
}

Field::Field(std::string&& name, const std::size_t number, std::string&& type,
             Message& message) noexcept
    : name_(std::move(name)), number_(number), type_(std::move(type)), message_(message) {
}

Field::Field(Field&& other) noexcept
    : name_(std::move(other.name_)),
      number_(other.number_),
      type_(std::move(other.type_)),
      message_(other.message_) {
  other.name_ = "";
  other.number_ = 0;
  other.type_ = "";
}

const std::string& Field::GetName() const {
  return name_;
}

const std::string& Field::GetType() const {
  return type_;
}

std::size_t Field::GetNumber() const {
  return number_;
}

Message& Field::GetMessage() const {
  return message_;
}

}  // namespace proto_buff_parser
