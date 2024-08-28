/* SD card reading for multi-axis FDM

 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 ** VCC - 5V
 ** GND - GND

  created 2024.08
  by YuShan
*/

#ifndef READSD_H_
#define READSD_H_

#include <SPI.h>
#include <SD.h>

#define CS_pin 10
#define FILE_NAME "PLA.gco"

class READSD {
public:
    READSD();
    ~READSD();
    bool init();
    void reading();
private:
};

extern class READSD ReadSD;

#endif /*READSD_H_*/