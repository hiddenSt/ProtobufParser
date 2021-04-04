#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_

#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/container/files_container.hpp>
#include <proto_buff_parser/container/packages_container.hpp>

namespace proto_buff_parser {
namespace container {

class ProtoBuffContainer {
 public:
  iterator::MessagesIterator& GetMessagesIterator();
  iterator::PackagesIterator& GetPackagesIterator();
  iterator::FilesIterator& GetFilesIterator();

  Message& FindMessage();
  Package& FindPackage();
  File& FindFile();

 private:
  MessagesContainer* messages_container_;
  FilesContainer* files_container_;
  PackagesContainer* packages_container_;
};

}  // namespace container
}  // namespace proto_buff_parser


#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_CONTAINER_PROTO_BUFF_CONTAINER_HPP_
