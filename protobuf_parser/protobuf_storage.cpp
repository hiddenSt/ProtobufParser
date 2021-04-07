#include "protobuf_storage.hpp"

namespace protobuf_parser {

ProtobufStorage::ProtobufStorage(std::size_t n_messages, std::size_t n_packages,
                                 std::size_t n_files, std::size_t n_directories)
    : messages_(n_messages), packages_(n_packages), files_(n_files), directories_(n_directories) {
}
void ProtobufStorage::AddMessage(const Message& message) {
  messages_[message.GetId()] = message;
}

void ProtobufStorage::AddPackage(const Package& package) {
  packages_[package.GetId()] = package;
}

void ProtobufStorage::AddDirectory(const Directory& directory) {
  directories_[directory.GetId()] = directory;
}

void ProtobufStorage::AddFile(const File& file) {
  files_[file.GetId()] = file;
}

const Message& ProtobufStorage::GetMessage(std::size_t id) {
  return messages_[id];
}

const Package& ProtobufStorage::GetPackage(std::size_t id) {
  return packages_[id];
}

const Directory& ProtobufStorage::GetDirectory(std::size_t id) {
  return directories_[id];
}

const File& ProtobufStorage::GetFile(std::size_t id) {
  return files_[id];
}

}  // namespace protobuf_parser