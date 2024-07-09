#ifndef _SMASH_LCD_DISPLAY_H
#define _SMASH_LCD_DISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace smash
{
    class LcdDisplay
    {
        LiquidCrystal_I2C lcd;
        void clearRow(int row);
    public:
        LcdDisplay(uint8_t addr, uint8_t sda, uint8_t scl);
        ~LcdDisplay() = default;
        void printRow(int row, const String& text);
    };
}

#endif