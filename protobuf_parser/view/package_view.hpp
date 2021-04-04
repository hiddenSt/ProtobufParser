#ifndef PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_PACKAGE_VIEW_HPP_
#define PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_PACKAGE_VIEW_HPP_

#include <protobuf_parser/iterator/packages_iterator.hpp>
#include <protobuf_parser/iterator/messages_iterator.hpp>
#include <protobuf_parser/container/messages_container.hpp>
#include <protobuf_parser/container/packages_container.hpp>
#include <protobuf_parser/container/protobuf_container.hpp>

namespace protobuf_parser {
namespace view {

class PackageView {
 public:
  PackageView(const container::ProtoBuffContainer& proto_buff_container, const Package& package);

  iterator::PackagesIterator& GetPackagesIterator();
  iterator::MessagesIterator& GetMessagesIterator();

 private:
  container::MessagesContainer* messages_container_;
  container::PackagesContainer* packages_container_;
  const container::ProtoBuffContainer& proto_buff_container_;
  const Package& package_;
};

}  // namespace view
}  // namespace protobuf_parser

#endif  // PROTOBUFPARSER_PROTOBUF_PARSER_VIEW_PACKAGE_VIEW_HPP_
