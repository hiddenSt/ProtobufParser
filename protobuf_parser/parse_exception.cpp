#include "parse_exception.hpp"

namespace protobuf_parser {

ParseException::ParseException(const std::string& filename, int line, int column,
                               const std::string& message)
    : filename_(filename), line_(line), column_(column), message_(message) {
}

const char* ParseException::what() const noexcept {
  std::string* error_message_ = new std::string{};
  *error_message_ += "Error in file " + filename_ + " at line " + std::to_string(line_) +
                     " in column " + std::to_string(column_) + " " + message_;
  return error_message_->c_str();
}

}  // namespace protobuf_parser
