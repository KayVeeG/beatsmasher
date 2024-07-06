#ifndef _SMASH_DISPLAY_H
#define _SMASH_DISPLAY_H

#include <cstddef>
#include <stdint.h>
#include "canvas.h"

namespace smash
{
    class Display
    {
    public:
        Display() = default;
        virtual ~Display() = default;

        virtual void drawCanvas(const Canvas& canvas);
        virtual void swapFrameBuffers() = 0;

        virtual size_t getWidth() const = 0;
        virtual size_t getHeight() const = 0;
    };
}

#endif