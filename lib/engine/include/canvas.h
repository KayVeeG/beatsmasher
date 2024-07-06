#ifndef _SMASH_CANVAS_H
#define _SMASH_CANVAS_H

#include "color.h"
#include <cstddef>

namespace smash
{
    class Canvas
    {
        Color *m_pixels;
        size_t m_width;
        size_t m_height;
    public:

        Canvas(size_t width, size_t height);
        ~Canvas();

        void setPixel(size_t x, size_t y, Color color);
        Color getPixel(size_t x, size_t y) const;

        void clearScreen(Color color = Color::black);

        size_t getWidth() const { return m_width; }
        size_t getHeight() const { return m_height; }

    };
}

#endif