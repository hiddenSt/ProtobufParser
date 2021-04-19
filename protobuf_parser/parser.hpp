#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_

#include <string>
#include <filesystem>
#include <set>
#include <exception>

#include <protobuf_parser/storage.hpp>
#include <google/protobuf/compiler/importer.h>

#include <protobuf_parser/stub_multiple_error_collector.hpp>

namespace protobuf_parser {


class Parser {
 public:
  explicit Parser(const std::filesystem::path& root_path);
  ~Parser();

  Storage GetStorage();

 private:
  std::string GetPathRelativeToRootDirectory(const std::string& full_path);
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

  google::protobuf::compiler::DiskSourceTree disk_source_tree_;
  StubMultipleErrorCollector error_collector_;
  std::filesystem::path root_path_;
  google::protobuf::compiler::Importer* importer_;
  std::set<std::string> directories_names_;
  std::set<std::string> packages_names_;
  std::set<std::string> files_names_;
};


}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_
