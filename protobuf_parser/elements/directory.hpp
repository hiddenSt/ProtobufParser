#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_

#include <string>
#include <protobuf_parser/elements/element.hpp>

namespace protobuf_parser {
namespace builders {
class DirectoryBuilder;
}

class Directory : public Element {
 public:
  Directory() = default;
  Directory(Directory&& directory);
  ~Directory() = default;

  // Non-copyable
  Directory(const Directory&) = delete;
  Directory& operator=(const Directory&) = delete;

  const std::string& GetName() const;
  bool HasParent() const noexcept;
  const Directory& GetParentDirectory() const;
  bool Contains(const std::string& file_name) const;

 private:
  friend class builders::DirectoryBuilder;

  std::string name_;
  Directory* parent_directory_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
