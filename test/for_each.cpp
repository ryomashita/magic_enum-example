#include <gtest/gtest.h>

#include <magic_enum_utility.hpp>

#include "magic_enum.hpp"
#include "sample_enums.h"

TEST(MagicEnumUtilityTest, ForEach) {
  magic_enum::enum_for_each<Color>([](auto val) {
    constexpr Color c_color = val;
    EXPECT_TRUE(magic_enum::enum_contains<Color>(c_color));
  });
}