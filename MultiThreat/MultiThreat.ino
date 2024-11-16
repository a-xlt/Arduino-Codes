

 int counter = 0 ;

void setup() 
{
Serial.begin(9600);

delay(2000);
}
void loop()
{
  if(counter == 30 )
  {
    counter = 0 ; 
    //save the file
    
    
  }
else
{
    counter++;
   //read the ethernet 
}
  delay(1000);
}
