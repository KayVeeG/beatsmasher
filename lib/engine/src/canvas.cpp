#include <smash.h>
#include <stdexcept>
#include <cstring>

namespace smash
{
    Canvas::Canvas(size_t width, size_t height)
        : m_width(width), m_height(height)
    {
        m_pixels = new Color[width * height];
    }

    Canvas::~Canvas()
    {
        delete[] m_pixels;
    }

    void Canvas::setPixel(size_t x, size_t y, Color color)
    {
        if (x >= m_width || y >= m_height)
        {
            throw std::out_of_range("Pixel coordinates out of bounds");
        }
        m_pixels[y * m_width + x] = color;
    }

    Color Canvas::getPixel(size_t x, size_t y) const
    {
        if (x >= m_width || y >= m_height)
        {
            throw std::out_of_range("Pixel coordinates out of bounds");
        }
        return m_pixels[y * m_width + x];
    }

    void Canvas::clearScreen(Color color)
    {
        for (size_t i = 0; i < m_width * m_height; ++i)
        {
            m_pixels[i] = color;
        }
    }
}