#include "directory_iterator.hpp"

namespace protobuf_parser {
namespace iterator {

DirectoryIterator::DirectoryIterator(std::vector<std::vector<std::size_t>>& adjacency_list_) : vertex_color_(adjacency_list_.size()) {

}

}
}