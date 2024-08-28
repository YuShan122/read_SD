#include "readSD.h"

class READSD ReadSD;

READSD::READSD() {}
READSD::~READSD() {}

bool READSD::init() {
    while(!Serial) {
    }
    Serial.print("Initializing SD card...");
    if(!SD.begin(CS_pin)) {
        Serial.println("initialization failed!");
        return false;
    }
    Serial.println("initialization done.");
    return true;
}

void READSD::reading() {
    File myFile;
    if(SD.exists(FILE_NAME)) {
        myFile = SD.open(FILE_NAME, FILE_READ);
        while(myFile.available()) {
            Serial.write(myFile.read());
        }
        myFile.close();
    }else{
        Serial.print(FILE_NAME);
        Serial.println(" does not exist.");
    }
}