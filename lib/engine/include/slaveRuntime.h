#ifndef _SLAVE_RUNTIME_H
#define _SLAVE_RUNTIME_H

#include <Arduino.h>
#include "runtime.h"
#include "speaker.h"
#include "slaveInputSystem.h"
#include "lcdDisplay.h"
#include <vector>
#include <memory>

namespace smash
{

    class SlaveRuntime : public Runtime
    {
        SlaveInputSystem m_inputSystem;
        HardwareSerial *m_masterSerial = nullptr;
        std::vector<std::shared_ptr<Speaker>> m_speakers;
    	std::shared_ptr<LcdDisplay> m_lcdDisplay = nullptr;
    public:

        SlaveRuntime() = default;
        virtual ~SlaveRuntime() = default;

        virtual void initialize() override;

        virtual void update() override;

        virtual void shutdown() override;

        void addSpeaker(std::shared_ptr<Speaker> speaker);

        void addButton(SlaveButton button);

        void setLcdDisplay(std::shared_ptr<LcdDisplay> lcdDisplay);
    };

}

#endif