#include <ESP8266WiFi.h>
void setup() 
{
WiFi.mode(WIFI_STA);
Serial.begin(9600);
Serial.println();
WiFi.begin("user","pass");
Serial.println();
while(WiFi.status()!= WL_CONNECTED)
{
  delay(100);
Serial.print(".");
}

Serial.println(WiFi.localIP());
}
void loop() {
  // put your main code here, to run repeatedly:

}
