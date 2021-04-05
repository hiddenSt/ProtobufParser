#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_

#include <string>

#include <protobuf_parser/parse_element.hpp>

namespace protobuf_parser {

class Directory : public ParseElement {
 public:
  explicit Directory(const std::string& names);
  explicit Directory(const std::string& name, Directory* parent_directory);
  const std::string& GetName() const;

 private:
  std::string name_;
  Directory* parent_directory_;
};

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
