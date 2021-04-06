#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_DIRECTORY_ITERATOR_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_DIRECTORY_ITERATOR_HPP_

#include <iterator>
#include <queue>
#include <vector>
#include <cstddef>

#include <protobuf_parser/parse_elements/directory.hpp>

namespace protobuf_parser {
namespace iterator {

class DirectoryIterator {
 public:
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t ;
  using value_type = Directory;
  using pointer = Directory*;
  using reference = Directory&;

  explicit DirectoryIterator(std::vector<std::vector<std::size_t>>& adjacency_list_);

  reference operator*() const;

 private:
  std::vector<std::vector<size_t>> adjacency_list_;
  std::queue<std::size_t> white_edges_;
  std::vector<char> vertex_color_;

};

}
}


#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_DIRECTORY_ITERATOR_HPP_
