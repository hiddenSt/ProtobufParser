#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_

#include <string>

#include <protobuf_parser/elements/file.hpp>

namespace protobuf_parser {
namespace builders {

class FileBuilder {
 public:
  FileBuilder() = default;
  FileBuilder(FileBuilder&& other) noexcept;

  // Non-copyable
  FileBuilder(const FileBuilder&) = delete;
  FileBuilder& operator=(const FileBuilder&) = delete;

  void SetUpName(const std::string& name) noexcept;
  void SetUpDirectory(Directory* directory) noexcept;
  void SetUpPackage(Package* package) noexcept;
  void SetUpPackageName(const std::string& package_name);
  const std::string& GetName() const;

  const std::string& GetPackageName() const;

  File& GetFile();

 private:
  File file_;
  std::string package_name_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_FILE_BUILDER_HPP_
