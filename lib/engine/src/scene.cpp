#include <smash.h>

namespace smash
{
    void Scene::update(double deltaTime)
    {
        
        for (Component& component : m_componentsContainer)
        {
            component.update(deltaTime);
        }
    }

    void Scene::render(Display& display)
    {
        for (Component& component : m_componentsContainer)
        {
            component.render(display);
        }
    }

    void Scene::instantiate(std::shared_ptr<GameObject> gameObject)
    {
        m_gameObjects.push_back(gameObject);
        for (const std::shared_ptr<Component>& component : gameObject->m_components)
        {
            m_componentsContainer.addComponent(*component);
        }
        gameObject->m_scene = this;
    }

    void Scene::destroy(std::shared_ptr<GameObject> gameObject)
    {
        for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
        {
            if (*it == gameObject)
            {
                m_gameObjects.erase(it);

                for (std::shared_ptr<Component> component : gameObject->m_components)
                {
                    m_componentsContainer.removeComponent(*component);
                    gameObject->m_scene = nullptr;
                }

                break;
            }
        }
    }
}