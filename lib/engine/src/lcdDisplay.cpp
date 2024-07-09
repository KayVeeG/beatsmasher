
#include <smash.h>

namespace smash
{
    LcdDisplay::LcdDisplay(uint8_t addr, uint8_t sda, uint8_t scl) : lcd(addr, 16, 2)
    {
        Wire.begin(sda, scl);
        lcd.init();
        lcd.backlight();
    }

    void LcdDisplay::clearRow(int row)
    {
        lcd.setCursor(0, row);
        for (int i = 0; i < 16; i++) { // Adjust 16 to match your LCD's column count
            lcd.print(" ");
        }
        lcd.setCursor(0, row); // Reset cursor to beginning of the row
    }

    void LcdDisplay::printRow(int row, const String& text)
    {
        clearRow(row);
        lcd.setCursor(0, row);
        lcd.print(text.c_str());
    }
}