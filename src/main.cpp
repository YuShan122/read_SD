#include "main.h"

void setup() {
  Serial.begin(BAUD_RATE_SERIAL);
  while (!Serial){}
  // ReadSD.init();
  Stm.init();
  // ReadSD.reading();
  
}

char transmitted_data[] = "get";
void loop() {
  char received_data[100] = {};
  Stm.getData(received_data);
  Stm.sendDate(transmitted_data);
  delay(100);
}