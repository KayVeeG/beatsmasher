#ifndef _SMASH_INPUT_DEVICE_H
#define _SMASH_INPUT_DEVICE_H

#include "inputSystem.h"

namespace smash
{
    class InputDevice
    {
    public:

        InputDevice() = default;
        virtual ~InputDevice() = default;

        virtual void provideInput(InputSystem& input);
    };
}

#endif