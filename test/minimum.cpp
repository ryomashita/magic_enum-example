#include <gtest/gtest.h>

#include <magic_enum.hpp>

enum class Color { RED = -10, GREEN = 0, BLUE = 10 };

TEST(MagickEnumBasicTest, toString) {
  auto color = Color::GREEN;
  auto color_name = magic_enum::enum_name(color);
  EXPECT_EQ(color_name, "GREEN");
}

TEST(MagickEnumBasicTest, fromString) {
  auto color_name = "BLUE";
  auto color = magic_enum::enum_cast<Color>(color_name);
  EXPECT_TRUE(color.has_value());
  EXPECT_TRUE(color.value() == Color::BLUE);

  // case insensitive : 大文字小文字を区別しない
  auto color_insensitive =
      magic_enum::enum_cast<Color>("blue", magic_enum::case_insensitive);
  EXPECT_TRUE(color_insensitive.has_value());
  EXPECT_TRUE(color_insensitive.value() == Color::BLUE);

  // 異常値の場合は value() で例外が発生する
  auto color_name_invalid = "INVALID";
  auto color_invalid = magic_enum::enum_cast<Color>(color_name_invalid);
  EXPECT_FALSE(color_invalid.has_value());
  EXPECT_THROW(color_invalid.value(), std::bad_optional_access);
  EXPECT_TRUE(color_invalid.value_or(Color::RED) == Color::RED);

  // 対処法：デフォルト値を指定する
  auto color_with_default =
      magic_enum::enum_cast<Color>(color_name_invalid).value_or(Color::RED);
  EXPECT_TRUE(color_with_default == Color::RED);
}

TEST(MagickEnumBasicTest, fromInteger) {
  constexpr auto color_value = 10;
  auto color = magic_enum::enum_cast<Color>(color_value);
  EXPECT_TRUE(color.has_value());
  EXPECT_TRUE(color.value() == Color::BLUE);

  // with default value
  auto color_with_default =
      magic_enum::enum_cast<Color>(color_value * 2).value_or(Color::RED);
  EXPECT_TRUE(color_with_default == Color::RED);
}
