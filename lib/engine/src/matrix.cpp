#include <smash.h>

namespace smash
{

    HUB75_I2S_CFG Matrix::ensureDBuff(HUB75_I2S_CFG mxconfig)
    {
        mxconfig.double_buff = true;
        return mxconfig;
    }

    Matrix::Matrix(HUB75_I2S_CFG mxconfig)
        : m_matrixPanel(ensureDBuff(mxconfig))
    {
        m_matrixPanel.begin();
    };

    void Matrix::drawCanvas(const Canvas &canvas)
    {
        for (size_t y = 0; y < canvas.getHeight(); y++)
        {
            for (size_t x = 0; x < canvas.getWidth(); x++)
            {
                m_matrixPanel.drawPixel(x, y, canvas.getPixel(x, y).toRGB565());
            }
        }
    }

    void Matrix::swapFrameBuffers()
    {
        m_matrixPanel.flipDMABuffer();
    }

    size_t Matrix::getWidth() const
    {
        return m_matrixPanel.width();
    }   

    size_t Matrix::getHeight() const
    {
        return m_matrixPanel.height();
    }   
}