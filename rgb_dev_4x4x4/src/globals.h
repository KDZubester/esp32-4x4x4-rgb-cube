#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

struct Color
{
    uint16_t r;
    uint16_t g;
    uint16_t b;
};

// Define common colors as constants
const Color RED = {255, 0, 0};
const Color GREEN = {0, 255, 0};
const Color BLUE = {0, 0, 255};
const Color WHITE = {255, 255, 255};
const Color BLACK = {0, 0, 0};
const Color YELLOW = {255, 255, 0};
const Color CYAN = {0, 255, 255};
const Color MAGENTA = {255, 0, 255};

#endif // COLOR_H