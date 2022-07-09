/*  Để có thể gửi và nhận tín hiệu phải mở 2 chương trình Arduino riêng biệt. Tức là, phải click chuột vào biểu tượng Arduino trenen Desktop 2 lần
 *  Kết nối:
 *          LoRa                  Arduino Uno R3
 *          VCC                         3.3V
 *          GND                         GND
 *          RST                          9
 *          DIO0                         2
 *          NSS                          10
 *          MOSI                         11
 *          MISO                         12
 *          SCK                          13
 *          
 * Nạp code mở Serial Monitor chọn No line ending, baud 9600.
 * Nhập chuỗi cần gửi và gửi đi
 */
#include <SPI.h>
#include <LoRa.h>

String gui;

void setup() {
  Serial.begin(9600);
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

void loop() {
  if(Serial.available())
  {
    gui = Serial.readString();
    // send packet
    LoRa.beginPacket();
    LoRa.print(gui);
    LoRa.endPacket();
  }
  delay(500);
}
