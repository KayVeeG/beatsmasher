#include <smash.h>
#include <sh.h>

namespace smash
{
    void Fragment::shade() const
    {
        for (size_t x = 0; x < gwidth(); ++x)
        {
            for (size_t y = 0; y < gheight(); ++y)
            {
                Color c = gpxl(x, y);
                frag(x, y, c);
                spxl(x, y, c);
            }
        }
    }
}