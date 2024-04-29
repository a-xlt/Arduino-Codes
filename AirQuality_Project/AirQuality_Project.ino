//================libraries================
#include <LiquidCrystal_I2C.h>
#include "CO2Sensor.h"
#include "DHT.h"
//================humidty and tempreture================
#define DHT11_PIN 2 
DHT dht11(DHT11_PIN, DHT11); 
//================CO2================
CO2Sensor co2Sensor(A0, 0.99, 100);
//================tvoc================
int sensorValue;
int digitalValue;
//================LCD================
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display 
//================Dust================
int measurePin = A2; //Connect dust sensor to Arduino A0 pin
int ledPower = 4;   //Connect 3 led driver pins of dust sensor to Arduino D2
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
//================Query Spliting For The LCD================
String splitQuery[6];
int StringCount = 0;

//================O3================
#define CALIBRATION_SAMPLE_TIMES 50 
#define CALIBRATION_SAMPLE_INTERVAL 500 
#define READ_SAMPLE_INTERVAL 50 
#define READ_SAMPLE_TIMES 5 

void setup() 
{
  //================CO2 INIT================
  co2Sensor.calibrate();

//================Tempreture and Humidity INIT================
  dht11.begin();
  

//================Dust INIT================
  pinMode(ledPower,OUTPUT);



Serial.begin(9600);
  
  Serial.println("Start");
  
  
}

void loop() 
{
  //================Get All Reads================



  int ReadHumd = dht11.readHumidity();
  
  int ReadTemp=  dht11.readTemperature();
  
  int ReadCo2=co2Sensor.read(); 
  
  int ReadTvoc = analogRead(1);
  

   digitalWrite(ledPower,LOW); 
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); 
  delayMicroseconds(sleepTime);
  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 170 * calcVoltage - 0.1;
 
 
  int ReadO3 = analogRead(4);
 


String query = String(ReadHumd)+","+String(ReadTemp)+","+String(ReadTvoc)+","+String(ReadCo2)+","+String(dustDensity)+","+String(ReadO3);

//================Send Reads To Serial================
  Serial.println(query);

  delay(2000);
  
}
