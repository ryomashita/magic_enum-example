
include(FetchContent)
FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG master
  DOWNLOAD_EXTRACT_TIMESTAMP OFF)

FetchContent_MakeAvailable(magic_enum)

function(enable_magic_enum target)
    target_include_directories(${target} PRIVATE ${magic_enum_SOURCE_DIR}/include/magic_enum)
endfunction()
