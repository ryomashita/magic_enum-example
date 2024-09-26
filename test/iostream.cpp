#include <gtest/gtest.h>

#include <magic_enum_iostream.hpp>

#include "sample_enums.h"
#include <sstream>

TEST(MagicEnumIostreamTest, ostream) {
  using magic_enum::iostream_operators::operator<<;
  std::stringstream ss;
  ss << Color::GREEN;
  EXPECT_EQ(ss.str(), "GREEN");
}

TEST(MagicEnumIostreamTest, istream) {
  using magic_enum::iostream_operators::operator>>;
  std::stringstream ss;
  ss << "BLUE";
  Color color = Color::RED;
  ss >> color;
  EXPECT_EQ(color, Color::BLUE);
}