int sensorValue;
int digitalValue;

void setup()
{
  Serial.begin(9600); // sets the serial port to 9600
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  sensorValue = analogRead(0); // read analog input pin 0
 
 
  Serial.println(sensorValue, DEC); // prints the value read

  delay(500); // wait 100ms for next reading
}