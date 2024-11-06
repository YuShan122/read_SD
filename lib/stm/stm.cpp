#include "stm.h"

class STM Stm;
SoftwareSerial SSerial(RX_PIN, TX_PIN);

STM::STM() {}
STM::~STM() {}

bool STM::init() {
    Serial.print("Initializing UART with STM...");
    SSerial.begin(BAUD_RATE_STM);
    SSerial.listen();
    Serial.print("initialization done.");
    return true;
}

void STM::getData(char* d) {
    char* data = d;
    while(!(SSerial.available() > WAIT_AVAILABLE_MIN)){}
    Serial.print(SSerial.available());
    Serial.print(" received data: ");
    while(SSerial.available() > 0){
        *data = (char)SSerial.read();
        data++;
    }
    Serial.println(d);
}

void STM::sendDate(char* data) {
    char* transmitted_data = data;
    SSerial.write(transmitted_data, strlen(transmitted_data));

}