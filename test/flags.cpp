#include "magic_enum.hpp"
#include <cstdint>
#include <gtest/gtest.h>

#include <magic_enum_flags.hpp>
#include <sys/types.h>

#include "sample_enums.h"

template <> struct magic_enum::customize::enum_range<Direction> {
  static constexpr bool is_flags = true;
};

// flag enum の場合は、enum_flags_cast を使う
TEST(MagicEnumFlagsTest, flags) {
  // from string
  constexpr auto dir = magic_enum::enum_flags_cast<Direction &>("UP|RIGHT");
  EXPECT_EQ(dir.has_value(), true);
  EXPECT_EQ((uint64_t)(dir.value()),
            (uint64_t)(Direction::UP | Direction::RIGHT));

  // from integer
  auto c_dir = magic_enum::enum_flags_cast<Direction>(3);
  EXPECT_EQ(c_dir.has_value(), true);
  EXPECT_EQ(c_dir.value(), Direction::LEFT | Direction::DOWN);

  // contains : 全てのbit-flagが定義済みenum要素に含まれるか判定
  EXPECT_EQ(magic_enum::enum_flags_contains<Direction>(32 + 1), false);
}

TEST(MagicEnumFlagsTest, bitwiseOp) {
  using namespace magic_enum::bitwise_operators;
  Direction dir_or = Direction::UP | Direction::RIGHT;
  EXPECT_TRUE(dir_or & Direction::UP);
  Direction dir_and = Direction::UP & Direction::RIGHT;
  EXPECT_FALSE(dir_and & Direction::UP);
}