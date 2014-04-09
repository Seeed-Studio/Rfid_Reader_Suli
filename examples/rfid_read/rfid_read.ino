#include "Suli.h"
#include "Wire.h"
#include "SoftwareSerial.h"

#include "Rfid_Reader_Arduino.h"


SoftwareSerial mySerial(A5, A4);

Rfid_Reader_Arduino rfid(&mySerial, -1);

void setup()
{
    Serial.begin(115200);

}

int len;
unsigned char dta[50];

void loop()
{
    if(rfid.isData())
    {
        len = rfid.getData(dta);
    }
    
    if(len>0)
    {
        for(int i=0; i<len; i++)
        {
            Serial.write(dta[i]);
        }
        len = 0;
    }
}