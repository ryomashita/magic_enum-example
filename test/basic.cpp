#include <cstddef>
#include <gtest/gtest.h>

// Magic_enum.hpp は基本の機能を提供する
// ライブラリには、これ以外にも複数のヘッダが含まれる
#include <magic_enum.hpp>

#include "sample_enums.h"

TEST(MagicEnumBasicTest, count) {
  auto count = magic_enum::enum_count<Color>();
  EXPECT_TRUE(count == 3);
}

TEST(MagicEnumBasicTest, typeName) {
  auto color = Color::GREEN;
  EXPECT_EQ(magic_enum::enum_type_name<decltype(color)>(), "Color");
}

TEST(MagicEnumBasicTest, isScoped) {
  EXPECT_TRUE(magic_enum::is_scoped_enum<Color>::value);
  EXPECT_FALSE(magic_enum::is_unscoped_enum<Color>::value);
}

TEST(MagicEnumBasicTest, toUnderlying) {
  EXPECT_EQ(typeid(magic_enum::underlying_type<Color>::type),
            typeid(std::underlying_type<Color>::type));
}

TEST(MagicEnumBasicTest, toString) {
  auto color = Color::GREEN;
  auto color_name = magic_enum::enum_name(color);
  EXPECT_EQ(color_name, "GREEN");
}

TEST(MagicEnumBasicTest, fromString) {
  auto color_name = "BLUE";
  auto color = magic_enum::enum_cast<Color>(color_name);
  EXPECT_TRUE(color.has_value());
  EXPECT_TRUE(color.value() == Color::BLUE);

  // case insensitive : 大文字小文字を区別しない
  auto color_insensitive =
      magic_enum::enum_cast<Color>("blue", magic_enum::case_insensitive);
  EXPECT_TRUE(color_insensitive.has_value());
  EXPECT_TRUE(color_insensitive.value() == Color::BLUE);

  // 比較関数をラムダ式で指定する
  auto func_case_insensitive = [](char lhs, char rhs) {
    return std::tolower(lhs) == std::tolower(rhs);
  };
  EXPECT_TRUE(
      magic_enum::enum_cast<Color>("blue", func_case_insensitive).value() ==
      Color::BLUE);

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

TEST(MagicEnumBasicTest, fromInteger) {
  constexpr auto color_value = 10;
  auto color = magic_enum::enum_cast<Color>(color_value);
  EXPECT_TRUE(color.has_value());
  EXPECT_TRUE(color.value() == Color::BLUE);

  // with default value
  auto color_with_default =
      magic_enum::enum_cast<Color>(color_value * 2).value_or(Color::RED);
  EXPECT_TRUE(color_with_default == Color::RED);
}

TEST(MagicEnumBasicTest, toInteger) {
  auto color = Color::BLUE;
  auto value = magic_enum::enum_integer(color);
  EXPECT_TRUE(value == 10);
}

TEST(MagicEnumBasicTest, fromIndex) {
  std::size_t index = 1;
  Color color = magic_enum::enum_value<Color>(index);
  EXPECT_TRUE(color == Color::GREEN);

  std::size_t index_maybe = 3;
  if (index_maybe < magic_enum::enum_count<Color>()) {
    Color color_invalid = magic_enum::enum_value<Color>(index_maybe);
  }
  // 異常値は assertion error が発生する (catch 不可)
  // Color color_invalid = magic_enum::enum_value<Color>(index_invalid);
}

TEST(MagicEnumBasicTest, toIndex) {
  auto color = Color::GREEN;
  auto index = magic_enum::enum_index(color);
  EXPECT_TRUE(index == 1);
}

TEST(MagicEnumBasicTest, contains) {
  auto color = Color::GREEN;
  EXPECT_TRUE(magic_enum::enum_contains<Color>(color));
  EXPECT_TRUE(magic_enum::enum_contains<Color>("RED"));
  EXPECT_TRUE(magic_enum::enum_contains<Color>(10));
  EXPECT_FALSE(magic_enum::enum_contains<Color>(3));
}

TEST(MagicEnumBasicTest, range) {
  constexpr std::array<Color, 3> colors = magic_enum::enum_values<Color>();
  // colors -> {Color::RED, Color::BLUE, Color::GREEN}
  constexpr std::array<std::basic_string_view<char>, 3> color_names =
      magic_enum::enum_names<Color>();
  // color_names -> {"RED", "BLUE", "GREEN"}
  constexpr std::array<std::pair<Color, std::basic_string_view<char>>, 3>
      color_entries = magic_enum::enum_entries<Color>();
  // color_entries -> {{Color::RED, "RED"}, {Color::BLUE, "BLUE"},
  // {Color::GREEN, "GREEN"}}
  EXPECT_TRUE(colors.size() == 3 && color_names.size() == 3 &&
              color_entries.size() == 3);
  for (auto color : colors) {
    auto name = magic_enum::enum_name(color);
    auto value = magic_enum::enum_integer(color);
    auto index = magic_enum::enum_index(color);
  }
}
