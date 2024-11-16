#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10   
#define RST_PIN 9   

MFRC522 rfid(SS_PIN, RST_PIN);  
 
byte targetUID[4] = {0x23, 0xD4, 0xF4, 0x12};

void setup() {
  Serial.begin(9600);            
  SPI.begin();                   
  rfid.PCD_Init();              
  delay(1000);                 
  Serial.println("RFID Reader Initialized. Place your card near the reader...");
}

void loop() {
 
  if (!rfid.PICC_IsNewCardPresent()) {
    delay(50);
    return;
  }

 
  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println("Error: Failed to read card serial.");
    delay(50);
    return;
  }

  Serial.print("Card UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();


  bool match = true;
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] != targetUID[i]) {
      match = false;
      break;
    }
  }

  
  if (match) {
    Serial.println("Hello Abbas");
  }
  else
  {
    Serial.println("Fuck You Mustafa Ali");
  }

   rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
