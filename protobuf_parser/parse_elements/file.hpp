#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_

#include <string>

#include <protobuf_parser/parse_elements/package.hpp>
#include <protobuf_parser/parse_elements/directory.hpp>

namespace protobuf_parser {

class File {
 public:
  File() = delete;
  File(const File& other) = default;
  explicit File(const std::string& name, Directory* directory, Package* package);
  ~File() = default;

  const std::string& GetName() const noexcept;
  const std::string GetPath() const noexcept;
  Directory* GetDirectory();
  Package* GetPackage();

  bool operator==(const File& other) const noexcept;
  bool operator!=(const File& other) const noexcept;

 private:
  std::string name_;
  Directory* directory_;
  Package* package_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
