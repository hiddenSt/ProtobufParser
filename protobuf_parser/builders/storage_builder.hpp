#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>
#include <protobuf_parser/storage.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/message_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>
#include <protobuf_parser/builders/package_builder.hpp>

namespace protobuf_parser {
namespace builders {

class StorageBuilder {
 public:
  void AddDirectoryBuilder(DirectoryBuilder* directory_builder);
  void AddPackageBuilder(PackageBuilder* package_builder);
  void AddFileBuilder(FileBuilder* file_builder);
  void AddMessageBuilder(MessageBuilder* message_builder);
  const Storage& GetStorage();

 private:
  void BuildDirectories();
  void BuildPackages();
  void BuildFiles();
  void BuildMessages();
  Package* FindParentForPackage(PackageBuilder* builder);
  Directory* FindParentForDirectory(DirectoryBuilder* builder);
  Package* FindPackage(const std::string& package_name);
  Directory* FindDirectoryForFile(const std::string& file_name);
  File* FindFile(const std::string& name);

  Storage storage_;
  std::vector<MessageBuilder*> message_builders_;
  std::vector<DirectoryBuilder*> directory_builders_;
  std::vector<FileBuilder*> file_builders_;
  std::vector<PackageBuilder*> package_builders_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_
