#include <smash.h>
#include <sh.h>

namespace smash
{
    void Fragment::shade() const {
        int pixelsModified = 0;

        for (size_t x = 0; x < gwidth(); ++x) {
            for (size_t y = 0; y < gheight(); ++y) {
                Color originalColor = gpxl(x, y);
                Color newColor = originalColor;
                frag(x, y, newColor);
                
                if (newColor != originalColor) {
                    spxl(x, y, newColor);
                    pixelsModified++;
                }
            }
        }
    }
}
