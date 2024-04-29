#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL91zCBa3A"
#define BLYNK_DEVICE_NAME "Controll LEDS"
#define BLYNK_AUTH_TOKEN "UNrYgGJMmvtoBSNYdLizzaNhoMhXFE5w"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "GhasanJ";
char pass[] = "abassghasannoury";

BLYNK_WRITE(V0){

   digitalWrite(D0,param.asInt());
}
BLYNK_WRITE(V1){

  digitalWrite(D1,param.asInt());
}
BLYNK_WRITE(V2){

  digitalWrite(D2,param.asInt());
}
BLYNK_WRITE(V3){

  digitalWrite(D3,param.asInt());
}
void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(D0 ,OUTPUT);
  pinMode(D1 ,OUTPUT);
  pinMode(D2 ,OUTPUT);
  pinMode(D3 ,OUTPUT);
  Blynk.begin(auth, ssid, pass,"blynk.cloud" ,80);
}

void loop()
{
  Blynk.run();
}
