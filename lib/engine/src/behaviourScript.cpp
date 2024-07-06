#include <smash.h>

namespace smash
{
    void BehaviourScript::addComponent(std::shared_ptr<Component> component)
    {
        if (getGameObject())
        {
            getGameObject()->addComponent(component);
        }
    }

    void BehaviourScript::removeComponent(std::shared_ptr<Component> component)
    {
        if (getGameObject())
        {
            getGameObject()->removeComponent(component);
        }
    }

    Component* BehaviourScript::getComponent(std::string typeName)
    {
        if (getGameObject())
        {
            return getGameObject()->getComponent(typeName);
        }

        return nullptr;
    }

    Scene* BehaviourScript::getScene()
    {
        if (getGameObject())
        {
            return getGameObject()->getScene();
        }

        return nullptr;
    }

    void BehaviourScript::instantiate(std::shared_ptr<GameObject> gameObject)
    {
        if (getScene())
        {
            getScene()->instantiate(gameObject);
        }
    }

    void BehaviourScript::destroy(std::shared_ptr<GameObject> gameObject)
    {
        if (getScene())
        {
            getScene()->destroy(gameObject);
        }
    }
}