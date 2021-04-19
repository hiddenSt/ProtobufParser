#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/file.hpp>
#include <protobuf_parser/storage.hpp>

namespace protobuf_parser {
namespace builders {

class StorageBuilder {
 public:
  void AddDirectories(const std::set<std::string>& directories);
  void AddPackages(const std::set<std::string>& packages);
  void AddFiles(const std::set<std::string>& files);
  void AddMessagesFromFiles(const google::protobuf::DescriptorPool* descriptor_pool);

 private:
  void SetUpPackagesParents();
  void SetUpDirectoriesParents();
  void AddNestedMessages(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageFields(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageReservedFieldsAndNumbers(Message* message,
                                          const google::protobuf::Descriptor* descriptor);
  Package* FindPackageForFileDescriptor(const google::protobuf::FileDescriptor* file_descriptor);
  Directory* FindDirectoryForFile(const std::string& file_name);

  Storage storage_;
};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_BUILDERS_STORAGE_BUILDER_HPP_
