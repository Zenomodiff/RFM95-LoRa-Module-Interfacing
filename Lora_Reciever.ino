/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 07:43 PM - date 27 may 2021
 Github Link :-- https://github.com/Zenomodiff/RFM95-LoRa-Module-Interfacing
 */

#include <Wire.h> 
#include <SPI.h>
#include <LoRa.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("LoRa Receiver");
  delay(2500);
  lcd.clear();

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
  Serial.println("Starting LoRa failed!");
  lcd.setCursor(0,0);
  lcd.print("LoRa Receiver");
    while (1);
  }
}

void loop() {
lcd.clear();
  int packetSize = LoRa.parsePacket();
  if (packetSize) {

    Serial.print("Received packet '");

    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    
    lcd.print(packet);

    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    delay(2000);
  }
}
