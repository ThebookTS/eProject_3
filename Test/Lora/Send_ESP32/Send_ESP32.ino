// BookTS
/*
ESP8266                                 SX1278 Pins               ESP32  
GND                                       GND                     GND
3.3V                                      VCC                     3.3V
D8                                        NSS                     P15
D7                                        MOSI                    P13
D6                                        MISO                    P12
D5                                        SCK                     P14
D0                                        RST                     P16
D2                                        DIO0                    P2
*/
//https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

#include <SPI.h>
#include <LoRa.h>

#define miso 12
#define mosi 13 
#define sck  14
#define ss   15
#define rst  16
#define dio0 2

void initLora();
void sendLora();
int i = 0;

void setup() {
  Serial.begin(115200);  
  initLora();
}

void loop() {
  sendLora();
  delay(1000);
}

// Cau hinh Lora
void initLora() {
  Serial.println("Lora Send");
  
  SPI.begin(sck, miso, mosi, ss);
  LoRa.setPins(ss, rst, dio0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  LoRa.setSpreadingFactor(10);    // He so lan truyen 6 -> 12 | mac dinh la 7
  LoRa.setSignalBandwidth(12345); // Bang thong | mac dinh la 125E3
  LoRa.crc();
  
  Serial.println("LoRa Gateway started");
}

// Doc Lora
void sendLora() {
  LoRa.beginPacket();
  LoRa.print(i);
  LoRa.endPacket();
  Serial.print("ESP32 - Send: ");
  Serial.println(i);
  i++;
}
