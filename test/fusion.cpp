#include <gtest/gtest.h>

#include <magic_enum_fuse.hpp>

#include "sample_enums.h"

TEST(MagickEnumFusionTest, CrossSwitch) {
  auto color = Color::GREEN;
  auto direction = Direction::UP;
  switch (magic_enum::enum_fuse(color, direction).value()) {
  case magic_enum::enum_fuse(Color::RED, Direction::RIGHT).value():
    FAIL();
    break;
  case magic_enum::enum_fuse(Color::GREEN, Direction::UP).value():
    SUCCEED();
    break;
  default:
    FAIL();
  }
}