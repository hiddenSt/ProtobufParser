#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <protobuf_parser/container/messages_container.hpp>
#include <protobuf_parser/container/packages_container.hpp>
#include <protobuf_parser/container/files_container.hpp>

namespace protobuf_parser {
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
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
