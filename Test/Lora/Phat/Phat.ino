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
#include <SPI.h>
#include <LoRa.h>

String gui;
int i = 0;

void initLora();
void sendLora();

void setup() {
  Serial.begin(9600);
  initLora();
}

void loop() {
  sendLora();
}

// Cau hinh lora
void initLora(){ 
  while (!Serial);
  Serial.println("LoRa Sender");
  
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSpreadingFactor(10);
  LoRa.setSignalBandwidth(12345);
  LoRa.crc();
}

// Gui Lora
void sendLora() {
  LoRa.beginPacket();
  LoRa.print(i);
  LoRa.endPacket();
  Serial.println(i);
  i++;
}
