#ifndef PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_PACKAGE_VIEW_HPP_
#define PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_PACKAGE_VIEW_HPP_

#include <proto_buff_parser/iterator/packages_iterator.hpp>
#include <proto_buff_parser/iterator/messages_iterator.hpp>
#include <proto_buff_parser/container/messages_container.hpp>
#include <proto_buff_parser/container/packages_container.hpp>
#include <proto_buff_parser/container/proto_buff_container.hpp>

namespace proto_buff_parser {
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
}  // namespace proto_buff_parser

#endif  // PROTOBUFFPARSER_PROTO_BUFF_PARSER_VIEW_PACKAGE_VIEW_HPP_
