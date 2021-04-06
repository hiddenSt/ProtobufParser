#ifndef PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_ITERATOR_HPP_
#define PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_ITERATOR_HPP_

#include <iterator>
#include <queue>
#include <vector>
#include <cstddef>

//#include <protobuf_parser/parse_elements/message.hpp>

namespace protobuf_parser {

template <typename T>
class Iterator {
 public:
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t ;
  using value_type = T;
  using pointer = T*;
  using reference = T&;

  explicit Iterator(value_type& element, std::vector<std::vector<std::size_t>>& adjacency_list_);

  reference operator*() const;
  pointer operator->();
  value_type& operator++();
  value_type operator++(int);
  friend bool operator== (const Iterator<value_type>& a, const Iterator<value_type>& b);
  friend bool operator!= (const Iterator<value_type>& a, const Iterator<value_type>& b);

  //const Message& GetMessage() const;

 private:
  std::vector<std::vector<size_t>> adjacency_list_;
  std::queue<std::size_t> white_edges_;
  std::vector<char> vertex_color_;
  value_type& element_;
};

template <typename T>
Iterator<T>::Iterator(T& element, std::vector<std::vector<std::size_t>>& adjacency_list_): element_(element)  {
}

}

#endif  // PROTOBUF_PARSER_PROTOBUF_PARSER_ITERATOR_ITERATOR_HPP_
