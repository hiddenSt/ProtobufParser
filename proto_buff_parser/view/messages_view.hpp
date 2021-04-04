#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_MESSAGES_VIEW_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_MESSAGES_VIEW_HPP_

#include <proto_buff_parser/container/proto_buff_container.hpp>
#include <proto_buff_parser/container/messages_container.hpp>

namespace proto_buff_parser {
namespace view {

class MessagesView {
 public:
  MessagesView(const container::ProtoBuffContainer& proto_buff_container, const Message& message);

  iterator::MessagesIterator& GetMessagesIterator();

 private:
  const container::ProtoBuffContainer& proto_buff_container_;
  const Message& message_;
  container::MessagesContainer* messages_container_;
};

}  // namespace view
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_MESSAGES_VIEW_HPP_
