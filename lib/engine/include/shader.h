#ifndef _SMASH_SHADER_H
#define _SMASH_SHADER_H

#include "shaderAttributes.h"
#include "canvas.h"

namespace smash
{
    class Shader
    {
    public:

        Shader() = default;
        ~Shader() = default;
        void execute(ShaderAttributes& attributes, Canvas& canvas) const;
    protected:

        virtual void shade() const = 0;
    };
}

#endif