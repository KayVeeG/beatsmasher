#include <smash.h>

namespace smash
{

    void initSlaveCom()
    {
        g_slaveCom.begin(9600, SERIAL_8N1, 32, 33);
    }

}