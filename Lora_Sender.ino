/*feel free to contact
 * sreeramaj53@gmail.com
 * www.youtube.com/ZenoModiff
 * last updated - time 07:45 PM - date 27 may 2021
 Github Link :-- https://github.com/Zenomodiff/RFM95-LoRa-Module-Interfacing
 */

#include <SPI.h>
#include <LoRa.h>

int counter = 0;
int Senderled = 5;
int Errorled = 6;


void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  pinMode(Senderled, OUTPUT);
  pinMode(Errorled, OUTPUT);
  digitalWrite(Senderled, LOW);
  digitalWrite(Errorled, LOW);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    digitalWrite(Errorled, HIGH);
    delay(2000);
    while (1);
  }
}

void loop() {
  digitalWrite(Senderled, LOW);
  digitalWrite(Errorled, LOW);
  
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("Hello From LoRA");
  digitalWrite(Senderled, HIGH);
  delay(500);
  digitalWrite(Senderled, LOW);
   
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(2000);
}
