#ifndef _smash_scene_hpp
#define _smash_scene_hpp

#include "componentsContainer.h"
#include "display.h"
#include <memory>
#include <vector>

namespace smash
{
    class GameObject;

    class Scene
    {
        friend class GameObject;
        std::vector<std::shared_ptr<GameObject>> m_gameObjects;
        ComponentsContainer m_componentsContainer;
    public:

        Scene() = default;
        virtual ~Scene() = default;

        void update(double deltaTime);
        void render(Display& display);

        void instantiate(std::shared_ptr<GameObject> gameObject);
        void destroy(std::shared_ptr<GameObject> gameObject);

    };
}



#endif