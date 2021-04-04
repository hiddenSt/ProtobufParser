#include "package.hpp"

namespace proto_buff_parser {

void Package::AddFile(const proto_buff_parser::File& file) {
  files_.AddFile(file);
}

Package& Package::GetParentPackage() {
  return parent_package_;
}

Message& Package::GetMessage(const std::string& name) {
  return messages_.GetMessage(name);
}

iterator::FilesIterator& Package::GetFilesIterator() {
  return files_.GetIterator();
}

iterator::MessagesIterator& Package::GetMessagesIterator() {
  return messages_.GetIterator();
}

container::MessagesContainer& Package::GetMessages() {
  return messages_;
}

}  // namespace proto_buff_parser
