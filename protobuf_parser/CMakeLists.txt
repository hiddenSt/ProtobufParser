get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

find_package(Protobuf REQUIRED)

set(PROTOBUF_PARSER_CXX_SOURCES
  parse_element.cpp
  protobuf_storage.cpp
  stub_multiple_error_collector.cpp
  parse_elements/field.cpp
  parse_elements/message.cpp
  parse_elements/file.cpp
  parse_elements/package.cpp
  parse_elements/directory.cpp
  serializers/json_serializer.cpp
  )

set(PROTOBUF_PARSER_HEADERS
  parse_element.hpp
  protobuf_storage.hpp
  protobuf_parser.hpp
  stub_multiple_error_collector.hpp
  parse_elements/field.hpp
  parse_elements/message.hpp
  parse_elements/file.hpp
  parse_elements/package.hpp
  parse_elements/directory.hpp
  serializers/json_serializer.hpp
  view/view.hpp
  )

add_library(protobuf_parser STATIC "${PROTOBUF_PARSER_HEADERS}" "${PROTOBUF_PARSER_CXX_SOURCES}")
target_include_directories(protobuf_parser PRIVATE "${LIB_INCLUDE_PATH}" "${Protobuf_INCLUDE_DIRS}")
target_link_libraries(protobuf_parser PRIVATE nlohmann_json::nlohmann_json "${Protobuf_LIBRARIES}")

# Linters

if (PROTOBUF_PARSER_DEVELOPER)

  if (CLANG_FORMAT_TOOL)
    add_clang_format_target(protobuf_parser_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

  if (CLANG_TIDY_TOOL)
    add_clang_tidy_target(protobuf_parser_clang_tidy ${CMAKE_CURRENT_SOURCE_DIR} ${LIB_INCLUDE_PATH} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

endif()