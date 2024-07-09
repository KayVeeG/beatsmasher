#include <smash.h>
#include <sh.h>

class DynamicRectFragment : public smash::Fragment {
protected:
    void frag(size_t x, size_t y, color& _color) const override {
        vec2 pos = *(vec2*)(gp("p_Position"));
        vec2 scal = *(vec2*)(gp("p_Scale"));

        // Allow partial rendering of rectangles
        if (x >= (size_t)pos.x && x < (size_t)(pos.x + scal.x) &&
            y >= (size_t)pos.y && y < (size_t)(pos.y + scal.y))
        {
            _color = color(255, 255, 255);  // White fill
        }
    }
};