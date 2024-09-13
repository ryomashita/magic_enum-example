include(${CMAKE_SCRIPTS_DIR}/install_gtest.cmake)

add_executable(MagickEnumBasicTest
    minimum.cpp
)
enable_magick_enum(MagickEnumBasicTest)
enable_gtest(MagickEnumBasicTest)
