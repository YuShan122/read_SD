#include "lcd.h"

class LCD Lcd;

//Initialize the LCD library
LiquidCrystal_I2C lcd(0x27, 20, 4); //inSTANCE

LCD::LCD() {}
LCD::~LCD() {}

void LCD::init() {
    uint8_t cols = 20;//LCD2004A
    uint8_t rows = 4;
    lcd.init();
    lcd.begin(cols, rows, LCD_5x8DOTS);
    lcd.backlight();
}

void LCD::print(char* d_) {
    lcd.clear();
    lcd.setCursor(7,0);
    lcd.print(d_);
}
