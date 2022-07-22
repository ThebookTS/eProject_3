// BookTS
/*      LoRa                  Arduino Nano
        VCC                         3.3V
        GND                         GND
        RST                          9
        DIO0                         2
        NSS                          10
        MOSI                         11
        MISO                         12
        SCK                          13          
*/
//https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

#include <SPI.h>
#include <LoRa.h>

void initLora();
void receiveLora();

void setup() {
  Serial.begin(9600);
  initLora();
}

void loop() {
  receiveLora();
  delay(1000);
}

// Cau hinh Lora
void initLora() {
  Serial.println("Lora Receive");

  if (!LoRa.begin(433E6)) {
    Serial.println("Lora Error");
    while (1);
  }
  
  LoRa.setSpreadingFactor(10);    // He so lan truyen 6 -> 12 | mac dinh la 7
  LoRa.setSignalBandwidth(12345); // Bang thong | mac dinh la 125E3
  LoRa.crc();

  Serial.println("LoRa Gateway started");
}

// Doc Lora
void receiveLora() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    if (LoRa.available()) {
      Serial.print("Arduino Nano - Receive: ");
      Serial.println((String)LoRa.readString());
    }
  }
}
