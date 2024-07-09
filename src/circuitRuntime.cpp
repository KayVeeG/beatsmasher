
#define SPEAKER_0 12
#define SPEAKER_1 13
#define SPEAKER_2 19
#define SPEAKER_3 18
#define SPEAKER_4 5
#define SPEAKER_5 15
#define LCD_ADDRESS 0x27
#define LCD_SDA 27
#define LCD_SCL 14

#ifndef _CIRCUI_RUNTIME_H
#define _CIRCUI_RUNTIME_H

#include <smash.h>

class CircuitRuntime : public smash::SlaveRuntime
    {
    public:
        CircuitRuntime() = default;
        ~CircuitRuntime() = default;

        void initialize() override
        {
            SlaveRuntime::initialize();
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(0, SPEAKER_0));
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(1, SPEAKER_1));
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(2, SPEAKER_2));
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(3, SPEAKER_3));
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(4, SPEAKER_4));
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(5, SPEAKER_5));
            SlaveRuntime::addButton(smash::SlaveButton(0, 36));
            SlaveRuntime::addButton(smash::SlaveButton(1, 39));
            SlaveRuntime::addButton(smash::SlaveButton(2, 34));
            SlaveRuntime::addButton(smash::SlaveButton(3, 35));
            SlaveRuntime::addButton(smash::SlaveButton(4, 32));
            SlaveRuntime::addButton(smash::SlaveButton(5, 33));
            SlaveRuntime::addButton(smash::SlaveButton(6, 25));
            SlaveRuntime::addButton(smash::SlaveButton(7, 26));
            SlaveRuntime::setLcdDisplay(std::make_shared<smash::LcdDisplay>(LCD_ADDRESS, LCD_SDA, LCD_SCL));
        }
        void update() override
        {
            SlaveRuntime::update();
        }
        void shutdown() override
        {
            SlaveRuntime::shutdown();
        }
    };
#endif