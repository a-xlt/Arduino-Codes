const int trigPin = 9; // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor
const int ironThreshold = 5; // Threshold for iron (adjust as needed)
const int paperThreshold = 10; // Threshold for paper (adjust as needed)
const int ironpin=13;
const int paperpin=12;


void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(ironpin, OUTPUT);
  pinMode(paperpin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration * 0.034) / 2; // Calculate distance in cm
  distance+=1;
  if(distance < 11)
  {
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Duration: ");
  Serial.println(duration);
  Serial.print("Duration/Distance: ");
  float x = duration/distance;
  Serial.println(x);
  Serial.println("========================");

  }
  else
  {
Serial.println("Other detected!");
Serial.println("========================");
  }
  delay(2500); // Delay for readability
}
