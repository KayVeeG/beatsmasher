#ifndef _SMASH_SLAVE_INPUT_SYSTEM
#define _SMASH_SLAVE_INPUT_SYSTEM

#include <map>
#include <vector>

namespace smash
{

    struct SlaveButton
    {
        int pin;
        int index;
        SlaveButton(int pin, int index);
    };

    class SlaveInputSystem
    {   
        HardwareSerial *m_masterSerial = nullptr;
        std::vector<SlaveButton> m_buttons;
        std::map<int, bool> m_buttonStates;
        std::map<int, bool> m_prevButtonStates;
    public:
        SlaveInputSystem() = default;
        ~SlaveInputSystem() = default;

        void setMasterSerial(HardwareSerial* masterSerial);

        void addButton(SlaveButton button);
        void update();
    };
}

#endif