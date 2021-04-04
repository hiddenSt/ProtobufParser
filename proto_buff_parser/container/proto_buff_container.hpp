#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_

#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/container/packages_container.hpp>
#include <proto_buff_parser/container/files_container.hpp>

namespace proto_buff_parser {
namespace container {

class ProtoBuffContainer {
 public:
  ProtoBuffContainer(MessagesContainer* messages_container, PackagesContainer* packages_container,
                     FilesContainer* files_container);

  iterator::MessagesIterator& GetMessagesIterator();
  iterator::PackagesIterator& GetPackagesIterator();
  iterator::FilesIterator& GetFilesIterator();

  const Message& FindMessage() const;
  const Package& FindPackage() const;
  const File& FindFile() const;

 private:
  MessagesContainer* messages_container_;
  FilesContainer* files_container_;
  PackagesContainer* packages_container_;
};

}  // namespace container
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_
