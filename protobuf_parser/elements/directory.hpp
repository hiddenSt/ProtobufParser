#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_

#include <string>
#include <filesystem>

#include <protobuf_parser/elements/element.hpp>

namespace protobuf_parser {
namespace builders {
class DirectoryBuilder;
}

class Directory : public Element {
 public:
  Directory();
  Directory(Directory&& directory);
  ~Directory() = default;

  Directory& operator=(Directory&& other);

  // Non-copyable
  Directory(const Directory&) = delete;
  Directory& operator=(const Directory&) = delete;

  const std::filesystem::path& GetPath() const;
  bool HasParent() const noexcept;
  const Directory& GetParentDirectory() const;
  bool Contains(const std::filesystem::path& file_path) const;

  std::map<std::string, std::string> Serialize() const override;

 private:
  friend class builders::DirectoryBuilder;

  std::filesystem::path path_;
  Directory* parent_directory_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSE_ELEMENTS_DIRECTORY_HPP_
