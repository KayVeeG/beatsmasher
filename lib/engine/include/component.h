#ifndef _SMASH_COMPONENT_H
#define _SMASH_COMPONENT_H

#include "gameObject.h"
#include "display.h"
#include <string>

namespace smash
{
    class Component
    {
        friend class ComponentsContainer;
        friend class GameObject;
        const int m_updateIndex = 0;
        GameObject* m_gameObject = nullptr;
    public:

        Component() = default;
        Component(int updateIndex) : m_updateIndex(updateIndex) {};
        virtual ~Component() = default;

        GameObject* getGameObject() const;

        virtual void update(double deltaTime) {};
        virtual void render(Display& display) {};
        virtual std::string getTypeName() const = 0;

    };
}

#endif