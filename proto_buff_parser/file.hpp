#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_

#include <string>

namespace proto_buff_parser {

class File {
 public:
  explicit File(const std::string& name, const std::string& path);

  const std::string& GetName() const noexcept;
  const std::string& GetPath() const noexcept;

 private:
  std::string name_;
  std::string path_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_FILE_HPP_
