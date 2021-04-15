#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_

#include <string>
#include <vector>
#include <queue>
#include <set>

#include <google/protobuf/descriptor.h>

#include <protobuf_parser/elements/directory.hpp>
#include <protobuf_parser/elements/message.hpp>
#include <protobuf_parser/elements/package.hpp>
#include <protobuf_parser/elements/file.hpp>

namespace protobuf_parser {

class Storage {
 public:
  template <typename T>
  class MessagesIterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Message;
    using pointer = Message*;
    using reference = Message&;

    MessagesIterator(T* root, Storage* storage);
    MessagesIterator(Storage* storage);

    reference operator*() const;
    pointer operator->();
    MessagesIterator<T>& operator++();
    const MessagesIterator<T> operator++(int);

    template <typename Y>
    friend bool operator==(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

    template <typename Y>
    friend bool operator!=(const MessagesIterator<Y>& a, const MessagesIterator<Y>& b);

   private:
    void Iterate();
    void EnqueueChildElements(T* element);
    void EnqueueCurrentElementMessages(T* element);

    std::queue<T*> elements_queue_;
    std::queue<Message*> current_element_messages_;
    Storage* storage_;
  };

 public:
  Storage() = default;
  ~Storage() = default;

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
  void AddMessageReservedFieldsAndNumbers(Message* message,
                                          const google::protobuf::Descriptor* descriptor);

  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
};

template <typename T>
Storage::MessagesIterator<T>::MessagesIterator(Storage* storage)
    : storage_(storage), current_element_messages_(), elements_queue_() {
}

template <typename T>
Message& Storage::MessagesIterator<T>::operator*() const {
  return *current_element_messages_.front();
}

template <typename T>
typename Storage::MessagesIterator<T>::pointer Storage::MessagesIterator<T>::operator->() {
  return current_element_messages_.front();
}

template <typename T>
Storage::MessagesIterator<T>& Storage::MessagesIterator<T>::operator++() {
  Iterate();
  return *this;
}

template <typename T>
const Storage::MessagesIterator<T> Storage::MessagesIterator<T>::operator++(int) {
  MessagesIterator<T> tmp = *this;
  Iterate();
  return tmp;
}

template <typename T>
bool operator==(const Storage::MessagesIterator<T>& a,
                const Storage::MessagesIterator<T>& b) {
  if (a.elements_queue_.empty() && b.elements_queue_.empty() && a.storage_ == b.storage_ &&
      a.current_element_messages_.empty() && b.current_element_messages_.empty()) {
    return true;
  }

  if (a.elements_queue_ != b.elements_queue_) {
    return false;
  }

  if (a.current_element_messages_ != b.current_element_messages_) {
    return false;
  }

  if (a.storage_ != b.storage_) {
    return false;
  }

  return true;
}

template <typename T>
bool operator!=(const Storage::MessagesIterator<T>& a,
                const Storage::MessagesIterator<T>& b) {
  return !(a == b);
}

template <typename T>
Storage::MessagesIterator<T> Storage::Begin(T* root) {
  return MessagesIterator<T>{root, this};
}

template <typename T>
Storage::MessagesIterator<T> Storage::End() {
  return MessagesIterator<T>{this};
}

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
