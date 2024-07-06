#ifndef _SMASH_SHADER_PROGRAM_H
#define _SMASH_SHADER_PROGRAM_H

#include "shaderAttributes.h"
#include "canvas.h"
#include "shader.h"
#include <memory>

namespace smash
{
    class ShaderProgram
    {
    private:
        struct ShaderNode
        {
            std::shared_ptr<Shader> shader;
            std::shared_ptr<ShaderNode> next;

            ShaderNode(std::shared_ptr<Shader> s) : shader(s), next(nullptr) {}
        };

        std::shared_ptr<ShaderNode> head;

    public:
        ShaderProgram();
        ~ShaderProgram();

        void addShader(std::shared_ptr<Shader> shdr);
        void removeShader(std::shared_ptr<Shader> shdr);
        void swapShaders(std::shared_ptr<Shader> shdr1, std::shared_ptr<Shader> shdr2);

        void use(ShaderAttributes& shattr, Canvas& cvs);
    };
}

#endif