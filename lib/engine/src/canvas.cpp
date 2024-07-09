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

    // Copy constructor
    Canvas::Canvas(const Canvas& other)
        : m_width(other.m_width), m_height(other.m_height)
    {
        m_pixels = new Color[m_width * m_height];
        std::memcpy(m_pixels, other.m_pixels, m_width * m_height * sizeof(Color));
    }

    // Assignment operator
    Canvas& Canvas::operator=(const Canvas& other)
    {
        if (this != &other) // Check for self-assignment
        {
            // Delete old resources
            delete[] m_pixels;
            
            // Copy new resources
            m_width = other.m_width;
            m_height = other.m_height;
            m_pixels = new Color[m_width * m_height];
            std::memcpy(m_pixels, other.m_pixels, m_width * m_height * sizeof(Color));
        }
        return *this;
    }

    void Canvas::fuze(const Canvas& other)
    {
        for (size_t y = 0; y < m_height; y++)
        {
            for (size_t x = 0; x < m_width; x++)
            {
                if (getPixel(x, y) == Color::black)
                {
                    setPixel(x, y, other.getPixel(x, y));
                }
            }
        }
    }

}