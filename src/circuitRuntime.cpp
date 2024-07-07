
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