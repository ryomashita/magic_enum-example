#include <gtest/gtest.h>

#include <magic_enum_switch.hpp>

#include "sample_enums.h"

TEST(MagicEnumSwitchTest, ConstexprSwitch) {
  Color color = Color::RED;
  magic_enum::enum_switch(
      [](auto val) {
        constexpr Color c_color = val;
        EXPECT_EQ(magic_enum::enum_integer(c_color), -10);
      },
      color);
}