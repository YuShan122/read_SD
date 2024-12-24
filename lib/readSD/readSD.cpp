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

bool READSD::readLine(char d_[]){
    if(myFile.available() <= 0) {
        myFile.close();
        return false;
    }
    int i = 0;
    while(myFile.available() > 0 && myFile.peek() != 10 && myFile.peek() != ';') {
        d_[i++] = myFile.read();
    }
    d_[i] = ' ';
    // Serial.print("d_: ");
    // Serial.println(d_);
    myFile.seek(myFile.position() + 1);
    return true;
}

bool READSD::readCommand(char d_[]){
    bool readNext = true;
    bool fileEnd = false;
    char read[LINE_MAX_LEN] = {};
    while(readNext){
        for(int i = 0; i < LINE_MAX_LEN; i++) read[i] = (char)0;
        fileEnd = !readLine(read);
        if(fileEnd) return false;
        if(read[0] == 'G' && read[1] == '1' && read[2] == ' ') readNext = false;
        else if(read[0] == 'G' && read[1] == '8' && read[2] == '7' && read[3] == ' ') readNext = false;
        else if(read[0] == 'M' && read[1] == '2' && read[2] == ' ') readNext = false;
        else if(read[0] == 'G' && read[1] == '4' && read[2] == ' ') readNext = false;
    }
    for(int i = 0; i < (int)strlen(read); i++){
        d_[i] = read[i];
    }
    return true;
}