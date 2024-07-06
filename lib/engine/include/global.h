#ifndef _SMASH_GLOBAL_H
#define _SMASH_GLOBAL_H

#include "inputSystem.h"

namespace smash
{
    static InputSystem* g_inputSystem = nullptr;

    void initSlaveCom();

    static HardwareSerial g_slaveCom(2);
}

#endif