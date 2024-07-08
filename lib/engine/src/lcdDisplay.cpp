
#include <smash.h>

namespace smash
{
    LcdDisplay::LcdDisplay(uint8_t addr, uint8_t sda, uint8_t scl) : lcd(addr, 16, 2)
    {
        Wire.begin(sda, scl);
        lcd.init();
        lcd.backlight();
    }

    void LcdDisplay::printRow(int row, const String& text)
    {
        lcd.setCursor(0, row);
        lcd.print(text);
    }
}