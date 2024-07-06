#ifndef _SMASH_FRAGMENT_H
#define _SMASH_FRAGMENT_H

#include "shader.h"

namespace smash
{
    class Fragment : public Shader
    {
    public:

        Fragment() = default;
        ~Fragment() = default;
    protected:
        void shade() const override;
        virtual void frag(size_t x, size_t y, Color& _color) const = 0;
    };
}

#endif