#ifndef _SMASH_MATRIX_H
#define _SMASH_MATRIX_H

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "display.h"

namespace smash
{
    class Matrix : public Display
    {
        MatrixPanel_I2S_DMA m_matrixPanel;
        HUB75_I2S_CFG ensureDBuff(HUB75_I2S_CFG dbuff);
    public:
        Matrix(HUB75_I2S_CFG mxconfig);
        virtual ~Matrix() = default;

        void drawCanvas(const Canvas& canvas) override;
        void swapFrameBuffers() override;

        size_t getWidth() const override;
        size_t getHeight() const override;
    };
}

#endif