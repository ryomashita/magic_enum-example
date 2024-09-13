
include(FetchContent)
FetchContent_Declare(
  magick_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG master
  DOWNLOAD_EXTRACT_TIMESTAMP OFF)

FetchContent_MakeAvailable(magick_enum)

function(enable_magick_enum target)
    target_include_directories(${target} PRIVATE ${magick_enum_SOURCE_DIR}/include/magic_enum)
endfunction()
