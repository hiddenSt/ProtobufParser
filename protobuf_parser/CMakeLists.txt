include(FetchContent)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.9.1
)

FetchContent_GetProperties(nlohmann_json)

if (NOT ${nlohmann_json}_POPULATED)
  FetchContent_Populate(nlohmann_json)
  add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR})
endif()

get_filename_component(LIB_INCLUDE_PATH ".." ABSOLUTE)
get_filename_component(LIB_PATH "." ABSOLUTE)

if (MSVC) 
  find_package(protobuf CONFIG REQUIRED)
else()
  find_package(Protobuf REQUIRED)
endif()


set(PROTOBUF_PARSER_CXX_SOURCES
  storage.cpp
  parser.cpp
  stub_multiple_error_collector.cpp
  parse_exception.cpp
  elements/element.cpp
  elements/enum.cpp
  elements/message.cpp
  elements/file.cpp
  elements/package.cpp
  elements/directory.cpp
  elements/fields/field.cpp
  elements/fields/builtin_field.cpp
  elements/fields/enum_field.cpp
  elements/fields/map_field.cpp
  elements/fields/message_field.cpp
  builders/message_builder.cpp
  builders/file_builder.cpp
  builders/directory_builder.cpp
  builders/package_builder.cpp
  builders/storage_builder.cpp
  builders/enum_builder.cpp
  builders/enum_field_type_builder.cpp
  builders/message_field_type_builder.cpp
  view/view.cpp
  )

set(PROTOBUF_PARSER_HEADERS
  storage.hpp
  parser.hpp
  stub_multiple_error_collector.hpp
  parse_exception.hpp
  elements/element.hpp
  elements/message.hpp
  elements/file.hpp
  elements/package.hpp
  elements/directory.hpp
  elements/enum.hpp
  elements/fields/field.hpp
  elements/fields/builtin_field.hpp
  elements/fields/message_field.hpp
  elements/fields/map_field.hpp
  elements/fields/enum_field.hpp
  builders/message_builder.hpp
  builders/file_builder.hpp
  builders/directory_builder.hpp
  builders/package_builder.hpp
  builders/storage_builder.hpp
  builders/enum_builder.hpp
  builders/enum_field_type_builder.hpp
  builders/message_field_type_builder.hpp
  serializers/json_serializer.hpp
  view/view.hpp
  )

add_library(protobuf_parser STATIC "${PROTOBUF_PARSER_HEADERS}" "${PROTOBUF_PARSER_CXX_SOURCES}")
target_include_directories(protobuf_parser PRIVATE "${LIB_INCLUDE_PATH}")
target_link_libraries(protobuf_parser PUBLIC nlohmann_json::nlohmann_json)

if (MSVC)
  target_link_libraries(protobuf_parser PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
  target_include_directories(protobuf_parser PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
else()
  target_link_libraries(protobuf_parser PUBLIC "${Protobuf_LIBRARIES}")
  target_include_directories(protobuf_parser PRIVATE "${Protobuf_INCLUDE_DIRS}")
endif()

# Linters

if (PROTOBUF_PARSER_DEVELOPER)

  if (CLANG_FORMAT_TOOL)
    add_clang_format_target(protobuf_parser_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

  if (CLANG_TIDY_TOOL)
    add_clang_tidy_target(protobuf_parser_clang_tidy ${CMAKE_CURRENT_SOURCE_DIR} ${LIB_INCLUDE_PATH} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

endif()