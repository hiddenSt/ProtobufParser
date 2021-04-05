get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

set(PROTOBUF_PARSER_CXX_SOURCES
  field.cpp
  message.cpp
  file.cpp
  package.cpp
  enum.cpp
  enum_field_type.cpp
  view/messages_view.cpp
  view/file_view.cpp
  view/package_view.cpp
  container/protobuf_container.cpp
  message_field_type.cpp
  )

set(PROTOBUF_PARSER_HEADERS
  field.hpp
  message.hpp
  file.hpp
  package.hpp
  enum.hpp
  enum_field_type.hpp
  field_type.hpp
  container/packages_container.hpp
  container/files_container.hpp
  container/messages_container.hpp
  container/protobuf_container.hpp
  container/fields_container.hpp
  iterator/messages_iterator.hpp
  iterator/files_iterator.hpp
  iterator/packages_iterator.hpp
  iterator/fields_iterator.hpp
  view/messages_view.hpp
  view/file_view.hpp
  view/package_view.hpp
  message_field_type.hpp
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