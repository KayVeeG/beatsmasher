#ifndef _SMASH_INPUT_SYSTEM_H
#define _SMASH_INPUT_SYSTEM_H

#include <map>

namespace smash
{
    class InputSystem
    {
        std::map<int, bool> m_buttonStates;
        std::map<int, bool> m_prevButtonStates;
    public:
        InputSystem() = default;
        ~InputSystem() = default;

        void registerInput(int index, bool state);
        void afterFrame();

        bool getButton(int index);
        bool getButtonPressed(int index);
        bool getButtonReleased(int index);
    };
}

#endif