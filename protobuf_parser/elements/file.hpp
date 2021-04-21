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

  // Movable
  File(File&& other) noexcept;

  // Non-copyable
  File(const File&) = delete;
  const File& operator=(const File&) = delete;

  const std::string& GetName() const noexcept;
  const std::string GetPath() const noexcept;
  const Directory& GetDirectory() const;
  const Package& GetPackage() const;

 private:
  friend class builders::FileBuilder;

  std::string name_;
  Directory* directory_;
  Package* package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
