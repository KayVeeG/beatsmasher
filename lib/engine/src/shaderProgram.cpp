#include <smash.h>
#include <stdexcept>

namespace smash
{
    ShaderProgram::ShaderProgram() : head(nullptr) {}

    ShaderProgram::~ShaderProgram() = default;

    void ShaderProgram::addShader(std::shared_ptr<Shader> shdr)
    {
        auto newNode = std::make_shared<ShaderNode>(shdr);
        newNode->next = head;
        head = newNode;
    }

    void ShaderProgram::removeShader(std::shared_ptr<Shader> shdr)
    {
        std::shared_ptr<ShaderNode> current = head;
        std::shared_ptr<ShaderNode> prev = nullptr;

        while (current)
        {
            if (current->shader == shdr)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void ShaderProgram::swapShaders(std::shared_ptr<Shader> shdr1, std::shared_ptr<Shader> shdr2)
    {
        std::shared_ptr<ShaderNode> node1 = nullptr;
        std::shared_ptr<ShaderNode> node2 = nullptr;
        std::shared_ptr<ShaderNode> current = head;

        while (current)
        {
            if (current->shader == shdr1)
                node1 = current;
            if (current->shader == shdr2)
                node2 = current;
            if (node1 && node2)
                break;
            current = current->next;
        }

        if (node1 && node2)
        {
            std::swap(node1->shader, node2->shader);
        }
        else
        {
            throw std::runtime_error("One or both shaders not found in the program");
        }
    }

    void ShaderProgram::use(ShaderAttributes& shattr, Canvas& cvs)
    {
        std::shared_ptr<ShaderNode> current = head;
        while (current)
        {
            current->shader->execute(shattr, cvs);
            current = current->next;
        }
    }
}