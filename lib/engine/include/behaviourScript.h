#ifndef _SMASH_BEHAVIOUR_SCRIPT_H
#define _SMASH_BEHAVIOUR_SCRIPT_H

#include <smash.h>

namespace smash
{
    class BehaviourScript : public smash::Component
    {
    public:

        BehaviourScript() = default;
        BehaviourScript(int updateIndex) : Component(updateIndex) {}
        ~BehaviourScript() = default;

        void addComponent(std::shared_ptr<Component> component);
        void removeComponent(std::shared_ptr<Component> component);

        Component* getComponent(std::string typeName);

        Scene* getScene();

        void instantiate(std::shared_ptr<GameObject> gameObject);
        void destroy(std::shared_ptr<GameObject> gameObject);        

    };
}

#endif