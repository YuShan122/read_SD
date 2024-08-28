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

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  // myFile = SD.open("PLA_MK3S_6m.gcode", FILE_WRITE);
  // if (myFile) {
  //   Serial.print("Writing to PLA_MK3S_6m.gcode...");
  //   myFile.println("testing 1, 2, 3.");
  //   myFile.close();
  //   Serial.println("done.");
  // } else {
  //   Serial.println("error opening PLA_MK3S_6m.gcode");
  // }

  bool exist = SD.exists("PLA.gco");
  Serial.println(exist);
  exist = SD.exists("test1.txt");
  Serial.println(exist);
  exist = SD.exists("test.txt");
  Serial.println(exist);
  myFile = SD.open("PLA.gco", FILE_READ);
  if (myFile) {
    Serial.println("hello.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening file");
  }
}

void loop() {
  
}