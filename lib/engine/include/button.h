#ifndef _SMASH_BUTTON_H
#define _SMASH_BUTTON_H

#include "inputDevice.h"
#include <string>

namespace smash
{
    class Button : public InputDevice
    {
        std::string m_buttonName;
        int m_pin;
    public:

        Button(std::string buttonName, int pin) : m_buttonName(buttonName), m_pin(pin) {}
        virtual ~Button() = default;

        void provideInput(InputSystem& input) override;
    };
}

#endif