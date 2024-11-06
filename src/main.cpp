#include "main.h"

void setup() {
  Serial.begin(BAUD_RATE_SERIAL);
  while(!Serial) {}
  ReadSD.init();
  Stm.init();
  // ReadSD.reading();

}

void loop() {
  char received_data[100] = {};
  char read[LINE_MAX_LEN] = {};

  ReadSD.readLine(read);
  while(read[0] == ';') {
    ReadSD.readLine(read);
  }
  Serial.println(read);

  Stm.getData(received_data);
  if(strcmp(received_data, "next") == 0){
    Stm.sendDate(read);
    Serial.println("receive next");
  }

  // delay(100);
}