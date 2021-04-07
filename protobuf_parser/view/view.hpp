#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
namespace protobuf_parser {
namespace view {

template <typename MessagesIterator, typename Serializer>
class View {
 public:
  explicit View(const MessagesIterator& messages_iterator, const Serializer& serializer);

  std::string Serialize();

 private:
  Serializer serializer_;
};

template <typename MessagesIterator, typename Serializer>
View<MessagesIterator, Serializer>::View(const MessagesIterator& messages_iterator,
                                         const Serializer& serializer) {
}

template <typename MessagesIterator, typename Serializer>
std::string View<MessagesIterator, Serializer>::Serialize() {
}

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
