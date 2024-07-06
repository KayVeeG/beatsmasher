#include "inputSystem.h"

namespace smash
{
    void InputSystem::setKey(const std::string& key, bool value)
    {
        m_keys[key] = value;
    }

    bool InputSystem::getKey(const std::string& key) const
    {
        return m_keys.at(key);
    }
}