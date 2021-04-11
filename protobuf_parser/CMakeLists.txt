get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

find_package(Protobuf REQUIRED)

set(PROTOBUF_PARSER_CXX_SOURCES
  protobuf_storage.cpp
  stub_multiple_error_collector.cpp
  parsed_elements/field.cpp
  parsed_elements/message.cpp
  parsed_elements/file.cpp
  parsed_elements/package.cpp
  parsed_elements/directory.cpp
  serializers/json_serializer.cpp
  )

set(PROTOBUF_PARSER_HEADERS
  protobuf_storage.hpp
  protobuf_parser.hpp
  stub_multiple_error_collector.hpp
  parsed_elements/field.hpp
  parsed_elements/message.hpp
  parsed_elements/file.hpp
  parsed_elements/package.hpp
  parsed_elements/directory.hpp
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