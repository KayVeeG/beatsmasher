#ifndef _SMASH_OBJECT_H
#define _SMASH_OBJECT_H

#include "scene.h"
#include <vector>
#include <memory>

namespace smash
{
    class Component;
    class GameObject
    {
        friend class Scene;
        Scene *m_scene = nullptr;
        std::vector<std::shared_ptr<Component>> m_components;
    public:
        GameObject() = default;
        virtual ~GameObject() = default;

        void addComponent(std::shared_ptr<Component> component);
        void removeComponent(std::shared_ptr<Component> component);
        
        Scene* getScene();

        Component* getComponent(std::string typeName);
    }; 
}

#endif