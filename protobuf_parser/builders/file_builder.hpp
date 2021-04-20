#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_

#include <string>

#include <protobuf_parser/elements/file.hpp>

namespace protobuf_parser {
namespace builders {

class FileBuilder {
 public:
  FileBuilder() = default;

  void SetUpName(const std::string& name) noexcept;
  void SetUpDirectory(Directory* directory) noexcept;
  void SetUpPackage(Package* package) noexcept;
  const std::string& GetName() const;

  File& GetFile();

 private:
  File file_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_
