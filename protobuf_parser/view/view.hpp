#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_

#include <string>
#include <queue>
#include <iterator>

#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/elements/enum.hpp>

namespace protobuf_parser {

class Storage;

namespace view {

template <typename T>
class View {
 public:
  class Iterator {
   public:
    using value_type = const Message;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::vector<const Message*>::iterator::difference_type;

    Iterator(const std::vector<const Message*>::iterator& iterator) : iterator_(iterator) {
    }

    const value_type& operator*() const {
      return **iterator_;
    }
    const value_type* operator->() {
      return *iterator_;
    }

    Iterator& operator++() {
      ++iterator_;
    }

    Iterator& operator++(int) {
      auto iterator = iterator_;
      iterator_++;
      return iterator;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      if (a.iterator_ == b.iterator_) {
        return true;
      }
      return false;
    }

    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return !(a == b);
    }

   private:
    std::vector<const Message*>::iterator iterator_;
  };

  class ConstIterator {
    using value_type = const Message;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::vector<const Message*>::const_iterator::difference_type;

    ConstIterator(const std::vector<const Message*>::const_iterator& iterator)
        : const_iterator_(iterator) {
    }

    const value_type& operator*() const {
      return **const_iterator_;
    }
    const value_type* operator->() {
      return *const_iterator_;
    }

    const Iterator& operator++() {
      ++const_iterator_;
    }

    Iterator& operator++(int) {
      auto iterator = const_iterator_;
      const_iterator_++;
      return iterator;
    }

    friend bool operator==(const ConstIterator& a, const ConstIterator& b) {
      if (a.const_iterator_ == b.const_iterator_) {
        return true;
      }
      return false;
    }

    friend bool operator!=(const ConstIterator& a, const ConstIterator& b) {
      return !(a == b);
    }

   private:
    std::vector<const Message*>::const_iterator const_iterator_;
  };

  explicit View(T* root, const Storage* storage);

  ConstIterator cbegin() {
    return ConstIterator{messages_.cbegin()};
  }
  ConstIterator cend() {
    return ConstIterator{messages_.cend()};
  }
  Iterator begin() {
    return Iterator(messages_.begin());
  }
  Iterator end() {
    return Iterator(messages_.end());
  }

  Iterator rbegin() {
  }
  Iterator rend() {
  }
  Iterator crbegin() {
  }
  Iterator crend() {
  }

 private:
  void EmplaceChildElements(const T* element, std::queue<const T*>& elements_queue);
  void AddElementsMessages(const T* element);

  std::vector<const Message*> messages_;
  std::vector<const Package*> packages_;
  std::vector<const File*> files_;
  std::vector<const Enum*> enums_;
  std::vector<const Directory*> directories_;
  T* root_;
  const Storage* storage_;
};

template <typename T>
View<T>::View(T* root, const Storage* storage) : root_(root), storage_(storage) {
  std::queue<const T*> elements_queue;
  elements_queue.emplace(root);

  while (!elements_queue.empty()) {
    auto element = elements_queue.front();
    elements_queue.pop();
    EmplaceChildElements(element, elements_queue);
    AddElementsMessages(element);
  }
}

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_VIEW_VIEW_HPP_
