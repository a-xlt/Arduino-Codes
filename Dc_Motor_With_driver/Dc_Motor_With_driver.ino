int  motor2pin2 = 5;

void setup() {
   
   
   
  pinMode(motor2pin2, OUTPUT);
 
 
  pinMode(10, OUTPUT);
   
}

void loop() {
   
  analogWrite(9, 255); //ENA  pin
   
   

   
  digitalWrite(motor2pin2, LOW);
  delay(3000);

  

   
  digitalWrite(motor2pin2, HIGH);
  delay(3000);
}
