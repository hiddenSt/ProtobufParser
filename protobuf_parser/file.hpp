#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_

#include <string>

namespace protobuf_parser {

class File {
 public:
  explicit File(const std::string& name, const std::string& path);

  const std::string& GetName() const noexcept;
  const std::string& GetPath() const noexcept;

 private:
  std::string name_;
  std::string path_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_FILE_HPP_
