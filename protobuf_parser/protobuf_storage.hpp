#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <string>
#include <vector>
#include <queue>

#include <protobuf_parser/parse_elements/directory.hpp>
#include <protobuf_parser/parse_elements/message.hpp>
#include <protobuf_parser/parse_elements/package.hpp>
#include <protobuf_parser/parse_elements/file.hpp>

namespace protobuf_parser {
// WARNING THERE IS A BUG!!!! Need to change references in child elements to their parents
class ProtobufStorage {
 public:
  template <typename T>
  class MessagesIterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Message;
    using pointer = Message*;
    using reference = Message&;

    MessagesIterator(T* root, ProtobufStorage* storage);
    MessagesIterator(ProtobufStorage* storage);

    reference operator*() const;
    pointer operator->();
    MessagesIterator<T>& operator++();
    MessagesIterator<T> operator++(int);

    template <typename Y>
    friend bool operator==(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

    template <typename Y>
    friend bool operator!=(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

   private:
    void Iterate();

    std::queue<T*> queue_;
    std::vector<Message*> current_element_messages_;
    ProtobufStorage* storage_;
    std::size_t index_;
  };

 public:
  ProtobufStorage();
  ~ProtobufStorage() = default;

  void AddMessages(std::vector<Message>&& messages);
  void AddPackages(std::vector<Package>&& packages);
  void AddDirectories(std::vector<Directory>&& directories);
  void AddFiles(std::vector<File>&& files);

  Directory* FindDirectory(const std::string& directory_path);
  Package* FindPackage(const std::string& package_name);

  template <typename T>
  MessagesIterator<T> Begin(T* root);

  template <typename T>
  MessagesIterator<T> End();

 private:
  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
};

template <typename T>
ProtobufStorage::MessagesIterator<T>::MessagesIterator(ProtobufStorage* storage)
    : storage_(storage), index_(0) {
}

template <typename T>
Message& ProtobufStorage::MessagesIterator<T>::operator*() const {
  return *current_element_messages_[index_];
}

template <typename T>
typename ProtobufStorage::MessagesIterator<T>::pointer
ProtobufStorage::MessagesIterator<T>::operator->() {
  return current_element_messages_[index_];
}

template <typename T>
ProtobufStorage::MessagesIterator<T>& ProtobufStorage::MessagesIterator<T>::operator++() {
  Iterate();
  return *this;
}

template <typename T>
ProtobufStorage::MessagesIterator<T> ProtobufStorage::MessagesIterator<T>::operator++(int) {
  MessagesIterator<T> tmp = this;
  Iterate();
  return tmp;
}

template <typename T>
bool operator==(const ProtobufStorage::MessagesIterator<T>& a,
                const ProtobufStorage::MessagesIterator<T>& b) {
  if (a.queue_.empty() && b.queue_.empty() && a.storage_ == b.storage_) {
    return true;
  }

  if (a.queue_ != b.queue_) {
    return false;
  }

  if (a.current_element_messages_ != b.current_element_messages_) {
    return false;
  }

  if (a.storage_ != b.storage_) {
    return false;
  }

  if (a.index_ != b.index_) {
    return false;
  }

  return true;
}

template <typename T>
bool operator!=(const ProtobufStorage::MessagesIterator<T>& a,
                const ProtobufStorage::MessagesIterator<T>& b) {
  return !(a == b);
}

template <typename T>
ProtobufStorage::MessagesIterator<T> ProtobufStorage::Begin(T* root) {
  return MessagesIterator<T>{root, this};
}

template <typename T>
ProtobufStorage::MessagesIterator<T> ProtobufStorage::End() {
  return MessagesIterator<T>{this};
}

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
