#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_FILE_VIEW_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_FILE_VIEW_HPP_

#include <proto_buff_parser/container/proto_buff_container.hpp>
#include <proto_buff_parser/container/files_container.hpp>
#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/container/packages_container.hpp>

namespace proto_buff_parser {
namespace view {

class FileView {
 public:
  FileView(const container::ProtoBuffContainer& proto_buff_container, const File& file);

  iterator::PackagesIterator& GetPackagesIterator();
  iterator::MessagesIterator& GetMessagesIterator();

 private:
  const container::ProtoBuffContainer& proto_buff_container_;
  container::MessagesContainer* messages_container_;
  container::PackagesContainer* packages_container_;
  const File& file_;
};

}  // namespace view
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_FILE_VIEW_HPP_
