#ifndef _LCD_DISPLAY_H
#define _LCD_DISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace smash
{
    class LcdDisplay
    {
        LiquidCrystal_I2C lcd;
    public:
        LcdDisplay(uint8_t addr, uint8_t sda, uint8_t scl);
        ~LcdDisplay() = default;
        void printRow(int row, const String& text);
    };
}

#endif