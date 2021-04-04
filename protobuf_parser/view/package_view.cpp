#include "package_view.hpp"

namespace protobuf_parser {
namespace view {

PackageView::PackageView(const container::ProtoBuffContainer& proto_buff_container,
                         const Package& package)
    : proto_buff_container_(proto_buff_container), package_(package) {
  // TODO: need to create containers with right data
}

iterator::PackagesIterator& PackageView::GetPackagesIterator() {
  return packages_container_->GetIterator();
}

iterator::MessagesIterator& PackageView::GetMessagesIterator() {
  return messages_container_->GetIterator();
}

}  // namespace view
}  // namespace protobuf_parser