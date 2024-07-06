#include <smash.h>
#include <algorithm>

namespace smash
{
    void GameObject::addComponent(std::shared_ptr<Component> component)
    {
        m_components.push_back(component);

        if (m_scene)
        {
            m_scene->m_componentsContainer.addComponent(*component);
        }
        component->m_gameObject = this;
    }

    void GameObject::removeComponent(std::shared_ptr<Component> component)
    {
        auto it = std::find(m_components.begin(), m_components.end(), component);
        if (it != m_components.end())
        {
            m_components.erase(it);

            if (m_scene)
            {
                m_scene->m_componentsContainer.removeComponent(*component);
                component->m_gameObject = nullptr;
            }
        }
    }

    Scene* GameObject::getScene()
    {
        return m_scene;
    }

    Component* GameObject::getComponent(std::string typeName)
    {
        for (std::shared_ptr<Component> component : m_components)
        {
            if (component->getTypeName() == typeName)
            {
                return component.get();
            }
        }

        return nullptr;
    }
}