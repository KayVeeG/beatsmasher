#include <smash.h>

namespace smash
{
    GameObject* Component::getGameObject() const
    {
        return m_gameObject;
    }
}