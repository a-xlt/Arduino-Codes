// Define the analog pin connected to the soil moisture sensor
const int soilMoisturePin = A0;

void setup() {
  // Start serial communication for output
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the soil moisture sensor
  int sensorValue = analogRead(soilMoisturePin);

  // Map the sensor value to a percentage for moisture level (optional)
  int moisturePercentage = map(sensorValue, 220, 1023, 100, 0);
 

  Serial.print("moisturePercentage: ");
  Serial.println(moisturePercentage);


  // Delay for stability
  delay(2000);  // 2 second delay before next reading
}
