#include "protobuf_storage.hpp"

namespace protobuf_parser {

const Message& ProtobufStorage::GetMessage(std::size_t id) {
  return messages_.find(id)->second;
}

const Package& ProtobufStorage::GetPackage(std::size_t id) {
  return packages_.find(id)->second;
}

const Directory& ProtobufStorage::GetDirectory(std::size_t id) {
  return directories_.find(id)->second;
}

const File& ProtobufStorage::GetFile(std::size_t id) {
  return files_.find(id)->second;
}

void ProtobufStorage::AddMessage(const Message& message) {
  messages_.insert(std::make_pair(message.GetId(), message));
}

void ProtobufStorage::AddPackage(const Package& package) {
  packages_.insert(std::make_pair(package.GetId(), package));
}

void ProtobufStorage::AddDirectory(const Directory& directory) {
  directories_.insert(std::make_pair(directory.GetId(), directory));
}

void ProtobufStorage::AddFile(const File& file) {
  files_.insert(std::make_pair(file.GetId(), file));
}

}  // namespace protobuf_parser