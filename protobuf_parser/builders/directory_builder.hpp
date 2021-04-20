#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_

#include <protobuf_parser/elements/directory.hpp>

namespace protobuf_parser {
namespace builders {

class DirectoryBuilder {
 public:
  DirectoryBuilder() = default;

  void SetUpParent(Directory* parent) noexcept;
  void SetUpName(const std::string& name) noexcept;
  Directory& GetDirectory();

 private:
  Directory directory_;
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
