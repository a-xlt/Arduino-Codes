const int analogPin = A2; // Analog pin for pH sensor
const float offsetVoltage = 0.00; // Offset voltage of the pH meter

void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  float sensorValue = analogRead(analogPin); // Read analog value from pH sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Convert analog value to voltage
  float pHValue =  (voltage ) * (10)/2 ; // Convert voltage to pH value

  Serial.print("pH Value: "); // Print pH value to Serial Monitor
  Serial.println(pHValue-12.45);


//Serial.println(voltage);
  delay(100); // Delay for better readability
}
