#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/storage.hpp>

namespace protobuf_parser {
namespace view {

template <typename T>
class View {
 public:
  class Iterator {
   public:
    using value_type = Message;

    value_type& operator*() const;
    value_type* operator->();

    Iterator& operator++();
    Iterator& operator++(int);

    friend bool operator==(const Iterator& a, const Iterator& b);
    friend bool operator!=(const Iterator& a, const Iterator& b);

   private:
    std::size_t current_message_index_;
  };

  explicit View(T* root, const Storage* storage);

  Iterator cbegin();
  Iterator cend();

 private:
  std::vector<Message*> messages_;
  T* root_;
};

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
