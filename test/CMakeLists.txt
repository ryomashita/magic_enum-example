include(${CMAKE_SCRIPTS_DIR}/install_gtest.cmake)

add_executable(MagickEnumBasicTest
    basic.cpp
)
enable_magick_enum(MagickEnumBasicTest)
enable_gtest(MagickEnumBasicTest)

add_executable(MagickEnumFusionTest
    fusion.cpp
)
enable_magick_enum(MagickEnumFusionTest)
enable_gtest(MagickEnumFusionTest)

add_executable(MagickEnumSwitchTest
    switch.cpp
)
enable_magick_enum(MagickEnumSwitchTest)
enable_gtest(MagickEnumSwitchTest)