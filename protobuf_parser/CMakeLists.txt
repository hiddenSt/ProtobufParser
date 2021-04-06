get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

set(PROTOBUF_PARSER_CXX_SOURCES
  parse_element.cpp
  protobuf_storage.cpp
  message_field_type.cpp
  parse_elements/field.cpp
  parse_elements/message.cpp
  parse_elements/file.cpp
  parse_elements/package.cpp
  parse_elements/directory.cpp
  iterator/directory_iterator.cpp
  iterator/package_iterator.cpp
  )

set(PROTOBUF_PARSER_HEADERS
  parse_element.hpp
  protobuf_storage.hpp
  enum_field_type.hpp
  field_type.hpp
  message_field_type.hpp
  parse_elements/field.hpp
  parse_elements/message.hpp
  parse_elements/file.hpp
  parse_elements/package.hpp
  parse_elements/enum.hpp
  parse_elements/directory.hpp
  view/view.hpp
  iterator/directory_iterator.hpp
  iterator/package_iterator.hpp
  )

add_library(protobuf_parser STATIC "${PROTOBUF_PARSER_CXX_SOURCES}" "${PROTOBUF_PARSER_HEADERS}")
target_include_directories(protobuf_parser PRIVATE "${LIB_INCLUDE_PATH}")

# Linters

if(PROTOBUF_PARSER_DEVELOPER)

  if(CLANG_FORMAT_TOOL)
    add_clang_format_target(protobuf_parser_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

  if(CLANG_TIDY_TOOL)
    add_clang_tidy_target(protobuf_parser_clang_tidy ${CMAKE_CURRENT_SOURCE_DIR} ${LIB_INCLUDE_PATH} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

endif()