#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
#include <queue>
#include <iterator>

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
    using iterator_category = std::forward_iterator_tag;

    Iterator(const View<T>& view, std::size_t index) : view_(view), current_message_index_(index) {
    }

    const value_type& operator*() const {
      return *view_.messages_[current_message_index_];
    }
    const value_type* operator->() {
      return view_.messages_[current_message_index_];
    }

    Iterator& operator++() {
      ++current_message_index_;
    }
    Iterator& operator++(int) {
      auto iterator = *this;
      current_message_index_++;
      return iterator;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      if (a.current_message_index_ >= a.view_.messages_.size() &&
          b.current_message_index_ >= b.view_.messages_.size()) {
        return true;
      }
      if (a.view_ == b.view_ && a.current_message_index_ == b.current_message_index_) {
        return true;
      }
      return false;
    }
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return !(a == b);
    }

   private:
    std::size_t current_message_index_;
    const View<T>& view_;
  };

  explicit View(T* root, const Storage* storage);

  Iterator cbegin() {
    return Iterator(*this, 0);
  }
  Iterator cend() {
    return Iterator(*this, messages_.size());
  }
  Iterator begin();
  Iterator end();
  Iterator rbegin();
  Iterator rend();
  Iterator crbegin();
  Iterator crend();

 private:
  void EmplaceElementChildren(const T* element, std::queue<const T*>& elements_queue);
  void AddElementsMessages(const T* element);
  std::vector<const Message*> messages_;
  T* root_;
  const Storage* storage_;
};

template <typename T>
View<T>::View(T* root, const Storage* storage) : storage_(storage) {
  std::queue<const T*> elements_queue;
  elements_queue.emplace(root);

  while (!elements_queue.empty()) {
    auto element = elements_queue.front();
    elements_queue.pop();
    EmplaceElementChildren(element, elements_queue);
    AddElementsMessages(element);
  }
}

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
