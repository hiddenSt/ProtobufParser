#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_EXCEPTION_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_EXCEPTION_HPP_

#include <exception>
#include <string>

namespace protobuf_parser {

class ParseException : public std::exception {
 public:
  ParseException(const std::string& filename, int line, int column, const std::string& message);
  const char* what() const noexcept override;

 private:
  std::string filename_;
  std::string message_;
  int line_;
  int column_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_EXCEPTION_HPP_
