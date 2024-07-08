
#define SPEAKER_0 26

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
            SlaveRuntime::addSpeaker(std::make_shared<smash::Speaker>(0, 12));
            SlaveRuntime::addButton(smash::SlaveButton(0, 36));
            SlaveRuntime::addButton(smash::SlaveButton(1, 39));
            SlaveRuntime::addButton(smash::SlaveButton(2, 34));
            SlaveRuntime::addButton(smash::SlaveButton(3, 35));
            SlaveRuntime::addButton(smash::SlaveButton(4, 32));
            SlaveRuntime::addButton(smash::SlaveButton(5, 33));
            SlaveRuntime::addButton(smash::SlaveButton(6, 25));
            SlaveRuntime::addButton(smash::SlaveButton(7, 26));
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