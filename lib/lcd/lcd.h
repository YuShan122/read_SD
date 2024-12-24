#ifndef LCD_H_
#define LCD_H_
/*INCLUDE*/
#include <LiquidCrystal_I2C.h>

/*DEFINE*/

/*CLASS*/
class LCD {
public:
    LCD();
    ~LCD();
    void init();
    void print(char*);
private:
};

extern class LCD Lcd;

#endif /*LCD_H_*/