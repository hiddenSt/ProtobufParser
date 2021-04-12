#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/parsed_elements/directory.hpp>
#include <protobuf_parser/parsed_elements/message.hpp>
#include <protobuf_parser/parsed_elements/package.hpp>
#include <protobuf_parser/parsed_elements/file.hpp>

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

    template <typename Y>
    friend bool operator==(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

    template <typename Y>
    friend bool operator!=(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

   private:
    void Iterate();
    void EnqueueChildElements(T* element);
    void PushBackCurrentElementMessages(T* element);

    std::queue<T*> queue_;
    std::vector<Message*> current_element_messages_;
    ProtobufStorage* storage_;
    std::size_t current_message_index_;
  };

 public:
  ProtobufStorage();
  ~ProtobufStorage() = default;

  void StoreDescriptorPool(const google::protobuf::DescriptorPool* descriptor_pool,
                           const std::set<std::string>& files,
                           const std::set<std::string>& directories,
                           const std::set<std::string>& packages);

  Directory* FindDirectory(const std::string& directory_path);
  Package* FindPackage(const std::string& package_name);

  template <typename T>
  MessagesIterator<T> Begin(T* root);

  template <typename T>
  MessagesIterator<T> End();

 private:
  void AddDirectories(const std::set<std::string>& directories);
  void AddPackages(const std::set<std::string>& packages);
  void AddFiles(const google::protobuf::DescriptorPool* descriptor_pool,
                const std::set<std::string>& files);
  void AddMessagesFromFiles(const google::protobuf::DescriptorPool* descriptor_pool);
  Package* FindPackageForFileDescriptor(const google::protobuf::FileDescriptor* file_descriptor);
  Directory* FindDirectoryForFile(const std::string& file_name);
  void SetUpPackagesParents();
  void SetUpDirectoriesParents();
  void AddNestedMessages(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageFields(Message* message, const google::protobuf::Descriptor* descriptor);
  void AddMessageReservedFieldsAndNumbers(Message* message, const google::protobuf::Descriptor* descriptor);

  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
};

template <typename T>
ProtobufStorage::MessagesIterator<T>::MessagesIterator(ProtobufStorage* storage)
    : storage_(storage), current_message_index_(0), current_element_messages_(), queue_() {
}

template <typename T>
Message& ProtobufStorage::MessagesIterator<T>::operator*() const {
  return *current_element_messages_[current_message_index_];
}

template <typename T>
typename ProtobufStorage::MessagesIterator<T>::pointer
ProtobufStorage::MessagesIterator<T>::operator->() {
  return current_element_messages_[current_message_index_];
}

template <typename T>
ProtobufStorage::MessagesIterator<T>& ProtobufStorage::MessagesIterator<T>::operator++() {
  Iterate();
  return *this;
}

template <typename T>
ProtobufStorage::MessagesIterator<T> ProtobufStorage::MessagesIterator<T>::operator++(int) {
  MessagesIterator<T> tmp = *this;
  Iterate();
  return tmp;
}

template <typename T>
bool operator==(const ProtobufStorage::MessagesIterator<T>& a,
                const ProtobufStorage::MessagesIterator<T>& b) {
  // TODO: there is a bug, last message can not iterates
  if (a.queue_.empty() && b.queue_.empty() && a.storage_ == b.storage_ &&
      (a.current_message_index_ == a.current_element_messages_.size() - 1 ||
       b.current_message_index_ == b.current_element_messages_.size() - 1)) {
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

  if (a.current_message_index_ != b.current_message_index_) {
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
