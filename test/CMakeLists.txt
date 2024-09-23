include(${CMAKE_SCRIPTS_DIR}/install_gtest.cmake)

add_executable(MagicEnumBasicTest
    basic.cpp
)
enable_magic_enum(MagicEnumBasicTest)
enable_gtest(MagicEnumBasicTest)

add_executable(MagicEnumFusionTest
    fusion.cpp
)
enable_magic_enum(MagicEnumFusionTest)
enable_gtest(MagicEnumFusionTest)

add_executable(MagicEnumSwitchTest
    switch.cpp
)
enable_magic_enum(MagicEnumSwitchTest)
enable_gtest(MagicEnumSwitchTest)

add_executable(MagicEnumUtilityTest
    for_each.cpp
)
enable_magic_enum(MagicEnumUtilityTest)
enable_gtest(MagicEnumUtilityTest)

add_executable(MagicEnumFlagTest
    flags.cpp
)
enable_magic_enum(MagicEnumFlagTest)
enable_gtest(MagicEnumFlagTest)
