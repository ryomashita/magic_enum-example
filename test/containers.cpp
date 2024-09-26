#include <gtest/gtest.h>

#include <magic_enum_containers.hpp>

#include "sample_enums.h"

TEST(MagicEnumContainersTest, array) {
  struct RGB {
    int r, g, b;
  };
  constexpr int rgb_max = 255;
  magic_enum::containers::array<Color, RGB> color_rgb_array{};
  color_rgb_array[Color::RED] = {rgb_max, 0, 0};
  color_rgb_array[Color::GREEN] = {0, rgb_max, 0};
  color_rgb_array[Color::BLUE] = {0, 0, rgb_max};
  EXPECT_EQ(magic_enum::containers::get<Color::BLUE>(color_rgb_array).b,
            rgb_max);
}

TEST(MagicEnumContainersTest, bitset) {
  using namespace magic_enum::bitwise_operators;
  constexpr magic_enum::containers::bitset<Color> color_bitset_red_green{
      Color::RED | Color::GREEN};
  EXPECT_FALSE(color_bitset_red_green.all());
  EXPECT_TRUE(color_bitset_red_green.any());
  EXPECT_TRUE(color_bitset_red_green.test(Color::RED));
}

TEST(MagicEnumContainersTest, set) {
  auto color_set = magic_enum::containers::set<Color>();
  EXPECT_TRUE(color_set.empty());
  color_set.insert(Color::RED);
  color_set.insert(Color::GREEN);
  color_set.insert(Color::BLUE);
  EXPECT_EQ(color_set.size(), 3);
}