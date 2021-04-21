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

find_package(Protobuf REQUIRED)

set(PROTOBUF_PARSER_CXX_SOURCES
  storage.cpp
  parser.cpp
  stub_multiple_error_collector.cpp
  elements/field.cpp
  elements/message.cpp
  elements/file.cpp
  elements/package.cpp
  elements/directory.cpp
  builders/message_builder.cpp
  builders/file_builder.cpp
  builders/directory_builder.cpp
  builders/package_builder.cpp
  builders/storage_builder.cpp
  view/view.cpp)

set(PROTOBUF_PARSER_HEADERS
  storage.hpp
  parser.hpp
  stub_multiple_error_collector.hpp
  elements/field.hpp
  elements/message.hpp
  elements/file.hpp
  elements/package.hpp
  elements/directory.hpp
  builders/message_builder.hpp
  builders/file_builder.hpp
  builders/directory_builder.hpp
  builders/package_builder.hpp
  builders/storage_builder.hpp
  serializers/json_serializer.hpp
  view/view.hpp
  )

add_library(protobuf_parser STATIC "${PROTOBUF_PARSER_HEADERS}" "${PROTOBUF_PARSER_CXX_SOURCES}")
target_include_directories(protobuf_parser PRIVATE "${LIB_INCLUDE_PATH}" "${Protobuf_INCLUDE_DIRS}")
target_link_libraries(protobuf_parser PUBLIC nlohmann_json::nlohmann_json "${Protobuf_LIBRARIES}")

# Linters

if (PROTOBUF_PARSER_DEVELOPER)

  if (CLANG_FORMAT_TOOL)
    add_clang_format_target(protobuf_parser_clang_format ${CMAKE_CURRENT_SOURCE_DIR} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

  if (CLANG_TIDY_TOOL)
    add_clang_tidy_target(protobuf_parser_clang_tidy ${CMAKE_CURRENT_SOURCE_DIR} ${LIB_INCLUDE_PATH} ${PROTOBUF_PARSER_HEADERS} ${PROTOBUF_PARSER_CXX_SOURCES})
  endif()

endif()