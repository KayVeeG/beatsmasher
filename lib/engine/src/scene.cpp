#include <smash.h>

namespace smash
{
    void Scene::update(double deltaTime)
    {

        for (Component& component : m_componentsContainer)
        {
            component.update(deltaTime);
        }

        for (GameObject* gameObject : m_gameObjectsToDestroy)
        {
            for (auto sceneGameObjectItr = m_gameObjects.begin(); sceneGameObjectItr != m_gameObjects.end(); ++sceneGameObjectItr)
            {
                if ((*sceneGameObjectItr).get() == gameObject)
                {
                    m_gameObjects.erase(sceneGameObjectItr);
                    for (const std::shared_ptr<Component>& component : gameObject->m_components)
                    {
                        m_componentsContainer.removeComponent(*component);
                    }
                    gameObject->m_scene = nullptr;
                    break;
                }
            }
        }
        m_gameObjectsToDestroy.clear();
    }

    void Scene::render(Display& display)
    {
        Canvas canvas(display.getWidth(), display.getHeight());
        for (Component& component : m_componentsContainer)
        {
            component.render(canvas);
        }
        display.drawCanvas(canvas);
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

    void Scene::destroy(GameObject* gameObject)
    {
        m_gameObjectsToDestroy.push_back(gameObject);
    }
}