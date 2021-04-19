#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/file.hpp>

namespace protobuf_parser {

class Storage {
 public:
  Storage() = default;
  ~Storage() = default;

  // Non-copyable
  Storage(const Storage&) = delete;
  Storage& operator=(const Storage&) = delete;

  // Non-movable
  Storage(Storage&&) = delete;
  Storage& operator=(Storage&&) = delete;

  void StoreDescriptorPool(const google::protobuf::DescriptorPool* descriptor_pool,
                           const std::set<std::string>& files,
                           const std::set<std::string>& directories,
                           const std::set<std::string>& packages);

 private:
  void AddDirectories(const std::set<std::string>& directories);
  void AddPackages(const std::set<std::string>& packages);
  void AddFiles(const google::protobuf::DescriptorPool* descriptor_pool,
                const std::set<std::string>& files);
  void AddMessagesFromFiles(const google::protobuf::DescriptorPool* descriptor_pool);
  Package* FindPackageForFileDescriptor(const google::protobuf::FileDescriptor* file_descriptor);
  Directory* FindDirectoryForFile(const std::string& file_name);
  void SetUpPackagesParents();
  void SetUpDirectoriesParents();
  void AddNestedMessages(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageFields(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageReservedFieldsAndNumbers(Message* message,
                                          const google::protobuf::Descriptor* descriptor);

  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
