#include "stm.h"

class STM Stm;
SoftwareSerial SSerial(RX_PIN, TX_PIN);

STM::STM() {}
STM::~STM() {}

bool STM::init() {
    SSerial.begin(BAUD_RATE_STM);
    SSerial.listen();
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