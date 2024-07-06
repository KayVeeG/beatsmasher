#include "Color.h"

namespace smash
{
    // Define static color instances
    Color Color::black(0, 0, 0);
    Color Color::white(255, 255, 255);
    Color Color::red(255, 0, 0);
    Color Color::green(0, 255, 0);
    Color Color::blue(0, 0, 255);

    uint16_t Color::toRGB565() const
    {
        return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
    }
}