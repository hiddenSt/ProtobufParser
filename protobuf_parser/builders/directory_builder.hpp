#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_

#include <filesystem>
#include <string>
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
  void SetUpPath(const std::filesystem::path& path) noexcept;
  bool IsParentOf(const std::filesystem::path directory_path);
  const std::filesystem::path& GetPath() const;
  Directory& GetDirectory();

 private:
  Directory directory_;
};

}  // namespace builders
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_DIRECTORY_BUILDER_HPP_
