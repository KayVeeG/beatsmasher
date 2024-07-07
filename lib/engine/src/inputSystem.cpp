#include <smash.h>

namespace smash
{
    void InputSystem::registerInput(int index, bool state)
    {
        m_buttonStates[index] = state;
    }

    void InputSystem::afterFrame()
    {
        // Shift frame states
        for (auto pair : m_buttonStates)
        {
            m_prevButtonStates[pair.first] = pair.second;
        }
    }

    bool InputSystem::getButton(int index)
    {
        return m_buttonStates[index];
    }

    bool InputSystem::getButtonPressed(int index)
    {
        return m_buttonStates[index] && !m_prevButtonStates[index];
    }

    bool InputSystem::getButtonReleased(int index)
    {
        return !m_buttonStates[index] && m_prevButtonStates[index];
    }
}