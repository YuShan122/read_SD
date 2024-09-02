#include "readSD.h"

class READSD ReadSD;
File myFile;

READSD::READSD() {}
READSD::~READSD() {}

bool READSD::init() {
    Serial.print("Initializing SD card...");
    if(!SD.begin(CS_pin)) {
        Serial.println("initialization failed!");
        return false;
    }
    if(SD.exists(FILE_NAME)) {
        myFile = SD.open(FILE_NAME, FILE_READ);
    }else{
        Serial.print(FILE_NAME);
        Serial.println(" does not exist.");
        return false;
    }
    Serial.println("initialization done.");
    return true;
}

void READSD::reading() {
    while(myFile.available()) {
        if(myFile.peek() == 10) Serial.print("LF"); //10: new line; 32: space
        Serial.write(myFile.read()); //return a char
        // Serial.println(myFile.read());
    }
    // myFile.close();
}

void READSD::readLine(char d_[]){
    int i = 0;
    while(myFile.available() > 0 && myFile.peek() != 10) {
        d_[i++] = myFile.read();
    }
    d_[i] = ' ';
    // Serial.print("d_: ");
    // Serial.println(d_);
    myFile.seek(myFile.position() + 1);
    return;
}