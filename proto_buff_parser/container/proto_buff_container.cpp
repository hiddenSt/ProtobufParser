#include "proto_buff_container.hpp"

namespace proto_buff_parser {
namespace container {

iterator::MessagesIterator& ProtoBuffContainer::GetMessagesIterator() {
  return messages_container_->GetIterator();
}

iterator::PackagesIterator& ProtoBuffContainer::GetPackagesIterator() {
  return packages_container_->GetIterator();
}

iterator::FilesIterator& ProtoBuffContainer::GetFilesIterator() {
  return files_container_->GetIterator();
}

}  // namespace container
}  // namespace proto_buff_parser