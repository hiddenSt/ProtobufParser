#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_

#include <string>

#include <proto_buff_parser/file.hpp>
#include <proto_buff_parser/message.hpp>
#include <proto_buff_parser/container/packages_container.hpp>
#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/container/files_container.hpp>

namespace proto_buff_parser {

class Package {
 public:
  void AddFile(const File& file);

  Package& GetParentPackage();
  Message& GetMessage(const std::string& name);

  iterator::FilesIterator& GetFilesIterator();
  iterator::MessagesIterator& GetMessagesIterator();
  container::MessagesContainer& GetMessages();

 private:
  container::FilesContainer& files_;
  container::MessagesContainer& messages_;
  Package& parent_package_;
};

}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_PACKAGE_HPP_
