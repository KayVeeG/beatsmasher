#include <smash.h>
#include <stdexcept>
#include <Arduino.h>

namespace smash
{
    ShaderRenderer::ShaderRenderer()
        : m_shaderAttributes(std::make_shared<ShaderAttributes>())
    {
    }

    void ShaderRenderer::render(Display& display)
    {
        Canvas canvas(display.getWidth(), display.getHeight());

        if (!m_shaderAttributes)
        {
             m_shaderAttributes = std::make_shared<ShaderAttributes>();    
        }

        // Use the shader program with the current attributes and canvas

        auto transform = (Transform*)getGameObject()->getComponent("Transform");
        if (transform)
        {
            if (transform->getPositionRef().y  == 28.00f)
            {
                Serial.println("RENDERING FIRST OBJECT");
            }
            else if (transform->getPositionRef().y == 24.00f)
            {
                Serial.println("RENDERING SECOND OBJECT");
            }
        }


        m_shaderProgram.use(*m_shaderAttributes, canvas);

        // Draw the canvas
        display.drawCanvas(canvas);
    }

    void ShaderRenderer::setShaderAttributes(std::shared_ptr<ShaderAttributes> shattr)
    {
        m_shaderAttributes = shattr;
    }

    std::shared_ptr<ShaderAttributes> ShaderRenderer::getShaderAttributes() const
    {
        return m_shaderAttributes;
    }

    ShaderProgram& ShaderRenderer::getShaderProgram()
    {
        return m_shaderProgram;
    }
}