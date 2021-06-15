#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_

#include <string>
#include <filesystem>
#include <set>
#include <exception>
#include <memory>

#include <google/protobuf/compiler/importer.h>

#include <protobuf_parser/stub_multiple_error_collector.hpp>
#include <protobuf_parser/storage.hpp>
#include <protobuf_parser/builders/message_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/file_builder.hpp>
#include <protobuf_parser/builders/directory_builder.hpp>
#include <protobuf_parser/builders/storage_builder.hpp>

namespace protobuf_parser {

class Parser {
 public:
  explicit Parser(const std::filesystem::path& root_path);
  ~Parser() = default;

  void Parse();
  Storage& GetStorage();

 private:
  using ProtobufImporter = google::protobuf::compiler::Importer;

  void ParseFromImporter();
  void AddDirectories();
  void AddPackages();
  void AddFiles();
  void AddMessages();
  void AddEnums();
  void AddNestedMessages(builders::MessageBuilder* builder,
                         const google::protobuf::Descriptor* descriptor);
  void AddMessageFields(builders::MessageBuilder* builder,
                        const google::protobuf::Descriptor* descriptor);
  void AddMessageReservedFieldsAndNumbers(builders::MessageBuilder* builder,
                                          const google::protobuf::Descriptor* descriptor);
  void AddEnumsFromMessages(const google::protobuf::Descriptor* message_descriptor,
                            const std::filesystem::path& file_path);
  std::string ReplaceBackwardSlashes(const std::string& path);

  google::protobuf::compiler::DiskSourceTree disk_source_tree_;
  StubMultipleErrorCollector error_collector_;
  std::filesystem::path root_path_;
  std::unique_ptr<ProtobufImporter> importer_;
  std::vector<builders::PackageBuilder> packages_builders_;
  std::vector<builders::MessageBuilder> messages_builders_;
  std::vector<builders::FileBuilder> files_builders_;
  std::vector<builders::DirectoryBuilder> directories_builders_;
  std::vector<builders::EnumBuilder> enum_builders_;
  builders::StorageBuilder storage_builder_;
  std::set<std::filesystem::path> directories_path_;
  std::set<std::string> packages_names_;
  std::set<std::filesystem::path> files_path_;
  Storage storage_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_PARSER_HPP_
