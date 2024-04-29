#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHT11_PIN 2
DHT dht11(DHT11_PIN, DHT11);


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  dht11.begin(); // initialize the sensor
  lcd.init();
  lcd.clear();         
  lcd.backlight();     
  
}

void loop() 
{
  int humi  = dht11.readHumidity();
  // read temperature as Celsius
  int tempC = dht11.readTemperature();
  
  lcd.setCursor(2,0);   
  lcd.print("Humidity:");
  lcd.print(humi);
  lcd.print("%");
  lcd.setCursor(4,1);   
  lcd.print("Temp:");
  lcd.print(tempC);
  lcd.print("C");



  delay(1000);
}