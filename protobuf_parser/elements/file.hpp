#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_

#include <string>

#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/directory.hpp>

namespace protobuf_parser {
namespace builders {
class FileBuilder;
}

class File {
 public:
  File() = default;
  ~File() = default;

  const std::string& GetName() const noexcept;
  const std::string GetPath() const noexcept;
  const Directory& GetDirectory();
  const Package& GetPackage();

  bool operator==(const File& other) const noexcept;
  bool operator!=(const File& other) const noexcept;

 private:
  friend class builders::FileBuilder;

  std::string name_;
  Directory* directory_;
  Package* package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
