#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_

#include <string>

namespace protobuf_parser {

class Directory {
 public:
  Directory() = delete;
  Directory(const Directory& other);
  explicit Directory(const std::string& names);
  explicit Directory(const std::string& name, Directory* parent_directory);
  ~Directory() = default;

  const std::string& GetName() const;
  Directory* GetParentDirectory();
  bool Contains(const std::string& file_name);

  bool operator==(const Directory& other) const noexcept;
  bool operator!=(const Directory& other) const noexcept;

 private:
  std::string name_;
  Directory* parent_directory_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
