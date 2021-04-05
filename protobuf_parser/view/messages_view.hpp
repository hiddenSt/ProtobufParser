#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_MESSAGES_VIEW_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_MESSAGES_VIEW_HPP_

#include <protobuf_parser/container/protobuf_storage.hpp>
#include <protobuf_parser/container/messages_container.hpp>

namespace protobuf_parser {
namespace view {

class MessagesView {
 public:
  MessagesView(const container::ProtobufStorage& proto_buff_container, const Message& message);

  iterator::MessagesIterator& GetMessagesIterator();

 private:
  const container::ProtobufStorage& proto_buff_container_;
  const Message& message_;
  container::MessagesContainer* messages_container_;
};

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_MESSAGES_VIEW_HPP_
