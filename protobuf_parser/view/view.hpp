#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
namespace protobuf_parser {
namespace view {

template <typename MessagesIterator, typename Serializer>
class View {
 public:
  explicit View(const MessagesIterator& messages_iterator, const Serializer& serializer);
  ~View() = default;

  std::string Serialize();

 private:
  Serializer serializer_;
  MessagesIterator iterator_;
};

template <typename MessagesIterator, typename Serializer>
View<MessagesIterator, Serializer>::View(const MessagesIterator& messages_iterator,
                                         const Serializer& serializer)
    : serializer_(serializer), iterator_(messages_iterator) {
}

template <typename MessagesIterator, typename Serializer>
std::string View<MessagesIterator, Serializer>::Serialize() {
  for (auto& message : iterator_) {
    serializer_.AddMessage(message);
  }
  return serializer_.Serialize();
}

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
