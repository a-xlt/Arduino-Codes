#include <SoftwareSerial.h>
 
#define RE 8
#define DE 7
 
const byte pyranometer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
byte values[8];
SoftwareSerial mod(2, 3);
 
void setup()
{
  Serial.begin(9600);
  mod.begin(4800);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  delay(1000);
}
 
void loop()
{
   
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  
  mod.write(pyranometer, sizeof(pyranometer));
  
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
  delay(10); 
   
  unsigned long startTime = millis();
  while (mod.available() < 7 && millis() - startTime < 1000) 
  {
    delay(1);
  }
 
   
  byte index = 0;
  while (mod.available() && index < 8) 
  {
    values[index] = mod.read();
    Serial.print(values[index], HEX);
    Serial.print(" ");
    index++;
  }
  Serial.println();
  int Solar_Radiation = int(values[5] << 8 | values[6]);
  Serial.print("Solar Radiation: ");
  Serial.print(Solar_Radiation);
  Serial.println(" W/m^2");
 
  delay(3000);
}