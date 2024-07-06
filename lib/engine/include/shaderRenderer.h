#ifndef _SMASH_SHADER_RENDERER_H
#define _SMASH_SHADER_RENDERER_H

#include "component.h"
#include "shaderProgram.h"
#include <memory>

namespace smash
{
    class ShaderRenderer : public Component
    {
        ShaderProgram m_shaderProgram;
        std::shared_ptr<ShaderAttributes> m_shaderAttributes;
    public:
        ShaderRenderer();
        ~ShaderRenderer() = default;

        void render(Display& display) override;

        void setShaderAttributes(std::shared_ptr<ShaderAttributes> shattr);

        std::shared_ptr<ShaderAttributes> getShaderAttributes() const;

        ShaderProgram& getShaderProgram();

        std::string getTypeName() const override { return "ShaderRenderer"; }

    };
}

#endif