#ifndef _SMASH_SH_H
#define _SMASH_SH_H

#include "shaderAttributes.h"
#include "canvas.h"

namespace smash {
    class ShaderAttributes;
    class Canvas;
    class Vector2;
    class Color;
}

class shAccess {
    friend class smash::Shader;
    static void setShattr(smash::ShaderAttributes& shattrref);
    static void setCvs(smash::Canvas& cvsref);
};

void* gp(std::string name);
float gf(std::string name);
smash::Vector2 gv(std::string name);
smash::Color gc(std::string name);

void sp(std::string name, void* pointer);
void sf(std::string name, float value);
void sv(std::string name, smash::Vector2 value);
void sc(std::string name, smash::Color value);

void spxl(size_t x, size_t y, smash::Color color);
smash::Color gpxl(size_t x, size_t y);

size_t gwidth();
size_t gheight();

typedef smash::Vector2 vec2;
typedef smash::Color color;

#endif