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
  void AddDirectory(DirectoryBuilder& directory_builder);
  void AddPackage(PackageBuilder& package_builder);
  void AddFiles(FileBuilder& file_builder);
  Storage& GetStorage() const noexcept;

 private:
  void SetUpPackagesParents();
  void SetUpDirectoriesParents();
  Package* FindPackageForFileDescriptor(const google::protobuf::FileDescriptor* file_descriptor);
  Directory* FindDirectoryForFile(const std::string& file_name);

  Storage storage_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_
