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
  class DirectoryIterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Message;
    using pointer = Message*;
    using reference = Message&;

    DirectoryIterator(Directory* root_directory, ProtobufStorage* storage);
    DirectoryIterator(ProtobufStorage* storage);

    reference operator*() const;
    pointer operator->();
    DirectoryIterator& operator++();
    DirectoryIterator operator++(int);
    friend bool operator==(const DirectoryIterator& a, const DirectoryIterator& b);
    friend bool operator!=(const DirectoryIterator& a, const DirectoryIterator& b);

   private:
    void Iterate();

    std::queue<Directory*> directories_queue_;
    std::vector<Message*> current_directory_messages_;
    ProtobufStorage* storage_;
    std::size_t index_;
  };

  class PackageIterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Message;
    using pointer = Message*;
    using reference = Message&;

    PackageIterator(ProtobufStorage* storage);
    PackageIterator(Package* root_package, ProtobufStorage* storage);

    reference operator*() const;
    pointer operator->();
    PackageIterator& operator++();
    PackageIterator operator++(int);
    friend bool operator==(const PackageIterator& a, const PackageIterator& b);
    friend bool operator!=(const PackageIterator& a, const PackageIterator& b);

   private:
    void Iterate();

    std::queue<Package*> packages_queue_;
    std::vector<Message*> current_package_messages_;
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

  DirectoryIterator DirectoryBegin(Directory* directory);
  DirectoryIterator DirectoryEnd();

  PackageIterator PackageBegin(Package* package);
  PackageIterator PackageEnd();

 private:
  std::vector<Message> messages_;
  std::vector<File> files_;
  std::vector<Package> packages_;
  std::vector<Directory> directories_;
};

}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_CONTAINER_PROTOBUF_CONTAINER_HPP_
