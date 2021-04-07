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

    friend bool operator==(const MessagesIterator<T>& a, const MessagesIterator<T>& b);
    friend bool operator!=(const MessagesIterator<T>& a, const MessagesIterator<T>& b);

   private:
    void Iterate();

    std::queue<T*> queue_;
    std::vector<Message*> current_element_messages_;
    ProtobufStorage* storage_;
    std::size_t index_;
  };

 public:
  ProtobufStorage(std::size_t n_messages, std::size_t n_packages, std::size_t n_files,
                  std::size_t n_directories);
  ~ProtobufStorage() = default;
  ProtobufStorage() = delete;

  void AddMessage(const Message& message);
  void AddPackage(const Package& package);
  void AddDirectory(const Directory& directory);
  void AddFile(const File& file);

  Message* GetMessage(std::size_t id);
  Package* GetPackage(std::size_t id);
  Directory* GetDirectory(std::size_t id);
  File* GetFile(std::size_t id);

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

// Directory specialization
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
