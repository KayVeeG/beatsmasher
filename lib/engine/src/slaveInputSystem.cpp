#include <smash.h>


namespace smash
{

    SlaveButton::SlaveButton(int index, int pin) : pin(pin), index(index)
    {
        pinMode(pin, INPUT);
    }

    void SlaveInputSystem::addButton(SlaveButton button)
    {
        m_buttons.push_back(button);
    }

    void SlaveInputSystem::update()
    {
        // Process local buttons
        for (auto button : m_buttons)
        {
            m_prevButtonStates[button.index] = m_buttonStates[button.index];
            m_buttonStates[button.index] = digitalRead(button.pin);

            if (m_buttonStates[button.index] != m_prevButtonStates[button.index] && m_masterSerial)
            {
                Communication::_CMD_BUTTON_CHANGE(button.index, m_buttonStates[button.index], *m_masterSerial);
            }
        }
    }

    void SlaveInputSystem::setMasterSerial(HardwareSerial* masterSerial)
    {
        m_masterSerial = masterSerial;
    }
}