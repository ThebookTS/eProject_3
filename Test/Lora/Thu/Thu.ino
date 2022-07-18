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

void getLora();
void initLora();

void setup() {
  Serial.begin(9600);
  initLora();
}

void loop() {
  getLora();
}

// Cau hinh Lora
void initLora() {
  while (!Serial);
  Serial.println("Lora Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Lora Error");
    while (1);
  }
  LoRa.setSpreadingFactor(10);
  LoRa.setSignalBandwidth(12345);
  LoRa.crc();
}

// Doc Lora
void getLora() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // read packet
    if (LoRa.available()) {
      Serial.println((String)LoRa.readString());
    }
  }
}
