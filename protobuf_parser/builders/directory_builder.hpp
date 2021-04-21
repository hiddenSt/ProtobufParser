#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_

#include <protobuf_parser/elements/directory.hpp>

namespace protobuf_parser {
namespace builders {

class DirectoryBuilder {
 public:
  DirectoryBuilder() = default;
  DirectoryBuilder(DirectoryBuilder&& other) noexcept;

  // Non-copyable
  DirectoryBuilder(const DirectoryBuilder&) = delete;
  DirectoryBuilder& operator=(const DirectoryBuilder&) = delete;

  void SetUpParent(Directory* parent) noexcept;
  void SetUpName(const std::string& name) noexcept;
  Directory& GetDirectory();
  bool IsParent(const std::string& directory_name);
  const std::string& GetName() const;

 private:
  Directory directory_;
};

}
}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
