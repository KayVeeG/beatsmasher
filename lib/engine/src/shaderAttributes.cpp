#include "ShaderAttributes.h"
#include <stdexcept>

namespace smash
{
    void ShaderAttributes::setPointer(std::string name, void* pointer)
    {
        m_pointers[name] = pointer;
    }

    void ShaderAttributes::setFloat(std::string name, float value)
    {
        m_floats[name] = value;
    }

    void ShaderAttributes::setVector(std::string name, Vector2 value)
    {
        m_vectors[name] = value;
    }

    void ShaderAttributes::setColor(std::string name, Color value)
    {
        m_colors[name] = value;
    }

    void* ShaderAttributes::getPointer(std::string name)
    {
        auto it = m_pointers.find(name);
        if (it != m_pointers.end())
        {
            return it->second;
        }
        throw std::runtime_error("Pointer attribute not found: " + name);
    }

    float ShaderAttributes::getFloat(std::string name)
    {
        auto it = m_floats.find(name);
        if (it != m_floats.end())
        {
            return it->second;
        }
        throw std::runtime_error("Float attribute not found: " + name);
    }

    Vector2 ShaderAttributes::getVector(std::string name)
    {
        auto it = m_vectors.find(name);
        if (it != m_vectors.end())
        {
            return it->second;
        }
        throw std::runtime_error("Vector attribute not found: " + name);
    }

    Color ShaderAttributes::getColor(std::string name)
    {
        auto it = m_colors.find(name);
        if (it != m_colors.end())
        {
            return it->second;
        }
        throw std::runtime_error("Color attribute not found: " + name);
    }
}