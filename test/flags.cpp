#include <gtest/gtest.h>

#include <magic_enum_flags.hpp>

#include "sample_enums.h"

template <> struct magic_enum::customize::enum_range<Direction> {
  static constexpr bool is_flags = true;
};

TEST(MagicEnumFlagsTest, flags) {
  constexpr auto direction = Direction::UP | Direction::RIGHT;
  //   auto directions = magic_enum::enum_flags_name(direction);
}