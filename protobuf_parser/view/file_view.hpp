#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_FILE_VIEW_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_FILE_VIEW_HPP_

#include <protobuf_parser/container/protobuf_storage.hpp>
#include <protobuf_parser/container/files_container.hpp>
#include <protobuf_parser/container/messages_container.hpp>
#include <protobuf_parser/container/packages_container.hpp>

namespace protobuf_parser {
namespace view {

class FileView {
 public:
  FileView(const container::ProtobufStorage& proto_buff_container, const File& file);

  iterator::PackagesIterator& GetPackagesIterator();
  iterator::MessagesIterator& GetMessagesIterator();

 private:
  const container::ProtobufStorage& proto_buff_container_;
  container::MessagesContainer* messages_container_;
  container::PackagesContainer* packages_container_;
  const File& file_;
};

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_FILE_VIEW_HPP_
