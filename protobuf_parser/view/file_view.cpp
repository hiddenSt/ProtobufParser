#include "file_view.hpp"

namespace protobuf_parser {
namespace view {

FileView::FileView(const container::ProtoBuffContainer& proto_buff_container, const File& file)
    : proto_buff_container_(proto_buff_container), file_(file) {
  // TODO: need to create containers with right data
}

iterator::PackagesIterator& FileView::GetPackagesIterator() {
  return packages_container_->GetIterator();
}

iterator::MessagesIterator& FileView::GetMessagesIterator() {
  return messages_container_->GetIterator();
}

}  // namespace view
}  // namespace protobuf_parser