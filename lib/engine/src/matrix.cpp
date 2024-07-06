#include <smash.h>

namespace smash
{

    HUB75_I2S_CFG matrix::ensureDBuff(HUB75_I2S_CFG mxconfig)
    {
        mxconfig.double_buff = true;
        return mxconfig;
    }

    matrix::matrix(HUB75_I2S_CFG mxconfig)
        : m_matrixPanel(ensureDBuff(mxconfig))
    {
        m_matrixPanel.begin();
    };

    void matrix::drawCanvas(const Canvas &canvas)
    {
        for (size_t y = 0; y < canvas.getHeight(); y++)
        {
            for (size_t x = 0; x < canvas.getWidth(); x++)
            {
                m_matrixPanel.drawPixel(x, y, canvas.getPixel(x, y).toRGB565());
            }
        }
    }

    void matrix::swapFrameBuffers()
    {
        m_matrixPanel.flipDMABuffer();
    }

    size_t matrix::getWidth() const
    {
        return m_matrixPanel.width();
    }   

    size_t matrix::getHeight() const
    {
        return m_matrixPanel.height();
    }   
}