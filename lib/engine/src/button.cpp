#include <smash.h>
#include <Arduino.h>

namespace smash
{
    void Button::provideInput(InputSystem& input)
    {
        input.setKey(m_buttonName, digitalRead(m_pin) == HIGH );
    }
}