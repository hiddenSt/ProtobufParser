include(FetchContent)

# Google Test
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0
)

FetchContent_GetProperties(gtest)

if (NOT ${gtest}_POPULATED)
  FetchContent_Populate(gtest)
  add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BINARY_DIR})
endif()

# Protocol Buffers 3
FetchContent_Declare(
  proto_buff3
  URL https://github.com/protocolbuffers/protobuf/releases/download/v3.15.7/protobuf-cpp-3.15.7.tar.gz
)

FetchContent_GetProperties(proto_buff3)

if (NOT ${proto_buff3}_POPULATED)
  FetchContent_Populate(proto_buff3)
  # add_subdirectory(${proto_buff3_SOURCE_DIR} ${proto_buff3_BINARY_DIR})
endif()