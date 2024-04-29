int joyX =0; //define the analog input place
int joyY =1; //define the analog input place
int joyB =2; //define the analog input place
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

}

void loop() 
{
 function1(analogRead(0) , analogRead(1) , analogRead(2));
}

void function1 (int Xaxis , int Yaxis , int Button)
{

  if (Xaxis ==0)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
        digitalWrite(2,LOW);

  }

 if (Yaxis ==0)
  {
    digitalWrite(6,HIGH);
  }
  else
  {
        digitalWrite(6,LOW);

  }
  
 if (Button ==0)
  {
    digitalWrite(7,HIGH);
  }
  else
  {
        digitalWrite(7,LOW);

  }
  
}
