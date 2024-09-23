#ifndef TEST_SAMPLE_ENUMS_H
#define TEST_SAMPLE_ENUMS_H

#include <cstdint>
enum class Color { RED = -10, GREEN = 0, BLUE = 10 };

// enum as bit flags
enum Direction : uint64_t { LEFT = 0x1, DOWN = 0x2, UP = 0x4, RIGHT = 0x8 };

#endif // TEST_SAMPLE_ENUMS_H
