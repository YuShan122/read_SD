#include "main.h"

void setup() {
  Serial.begin(BAUD_RATE_SERIAL);
  while(!Serial) {}
  ReadSD.init();
  Stm.init();
  Lcd.init();
  // ReadSD.reading();
}

void loop() {
  char received_data[100] = {};
  char send_data[LINE_MAX_LEN] = {};
  static bool fileEnd = false;

  fileEnd = !ReadSD.readCommand(send_data);
  if(fileEnd) {/*stop reading*/ return;}
  Serial.println(send_data);

  Stm.getData(received_data);
  if(strcmp(received_data, "next") == 0){
    Stm.sendDate(send_data);
    // Serial.println("receive next");
    if(send_data[0] == 'G' && send_data[1] == '8' && send_data[2] == '7'){
      Lcd.print(send_data);
    }
  }

  // delay(100);
}