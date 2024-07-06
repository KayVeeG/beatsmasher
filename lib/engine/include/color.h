#ifndef _SMASH_COLOR_H
#define _SMASH_COLOR_H

#include <stdint.h>

namespace smash
{
    struct Color
    {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        Color() = default;
        Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

        uint16_t toRGB565() const;

        static Color black;
        static Color white;
        static Color red;
        static Color green;
        static Color blue;

    };
}

#endif