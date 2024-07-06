#ifndef _SMASH_SHADER_ATTRIBUTES_H
#define _SMASH_SHADER_ATTRIBUTES_H

#include "Vector2.h"
#include "color.h"
#include <map>
#include <string>

namespace smash
{
    class ShaderAttributes
    {
        std::map<std::string, void*> m_pointers;
        std::map<std::string, float> m_floats;
        std::map<std::string, Vector2> m_vectors;
        std::map<std::string, Color> m_colors;
    public:
        ShaderAttributes() = default;
        ~ShaderAttributes() = default;

        void setPointer(std::string name, void* pointer);
        void setFloat(std::string name, float value);
        void setVector(std::string name, Vector2 value);
        void setColor(std::string name, Color value);

        void* getPointer(std::string name);
        float getFloat(std::string name);
        Vector2 getVector(std::string name);
        Color getColor(std::string name);
    };
}

#endif