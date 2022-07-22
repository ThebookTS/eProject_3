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

int i = 0;

void initLora();
void sendLora();

void setup() {
  Serial.begin(9600);
  initLora();
}

void loop() {
  sendLora();
  delay(2000);
}

// Cau hinh lora
void initLora(){ 
  Serial.println("LoRa Send");
  
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  LoRa.setSpreadingFactor(10);    // He so lan truyen 6 -> 12 | mac dinh la 7
  LoRa.setSignalBandwidth(12345); // Bang thong | mac dinh la 125E3
  LoRa.crc();

  Serial.println("LoRa Gateway started");
}

// Gui Lora
void sendLora() {
  LoRa.beginPacket();
  LoRa.print(i);
  LoRa.endPacket();
  Serial.print("Arduno nano - Send: ");
  Serial.println(i);
  i++;
}
