/*
    Serial communication with STM32h723 nucleo-144 board.

    Arthor: YuShan
    Created: Aug, 2024
*/

#ifndef STM_H_
#define STM_H_

/*INCLUDE*/
#include "Arduino.h"
#include "SoftwareSerial.h"

/*DEFINE*/
#define RX_PIN 6
#define TX_PIN 7
#define BAUD_RATE_STM 14400
#define WAIT_AVAILABLE_MIN 0

/*CLASS*/
class STM {
public:
    STM();
    ~STM();
    bool init();
    void getData(char*);
    void sendDate(char*);
private:

};

extern class STM Stm;

#endif