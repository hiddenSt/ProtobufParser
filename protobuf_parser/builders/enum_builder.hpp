#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_BUILDER_HPP_

#include <protobuf_parser/elements/enum.hpp>

namespace protobuf_parser {
namespace builders {

class EnumBuilder {
 public:
  EnumBuilder() = default;

  void SetUpName(const std::string& name);
  void SetUpParentMessage(Message* message);
  void SetUpFile(File*  file);
  void AddValue(const std::string& name, std::size_t number);
  void SetUpFilePath(const std::filesystem::path& path);
  void SetUpMessageName(const std::string& name);

  const std::string& GetMessageName() const;
  const std::filesystem::path& GetFilePath() const;

  Enum& GetEnum();

 private:
  Enum enum_;
  std::filesystem::path file_path_;
  std::string message_name_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_ENUM_BUILDER_HPP_
