#include <IRremote.h>
IRrecv res (13); //port of reciver
decode_results results; //the code of the input
unsigned int num_1 = 16753245;//value of preesing number 1
bool num1_state =false;//state of the light OFF->false/ON->true
unsigned int num_2 = 16736925;//value of preesing number 2
bool num2_state =false;//state of the light OFF->false/ON->true
unsigned int num_3 = 16769565;//value of preesing number 3
bool num3_state =false;//state of the light OFF->false/ON->true
unsigned int num_4 = 16720605;//value of preesing number 4
bool num4_state =false;//state of the light OFF->false/ON->true
unsigned int num_5 = 16712445;//value of preesing number 5
bool num5_state =false;//state of the light OFF->false/ON->true
unsigned int num_6 = 16761405;//value of preesing number 5
void setup()
{
Serial.begin(9600);//serial screen
res.enableIRIn();//activ the reciver
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}
void loop() {
if (res.decode(&results))//if there are signal
{
  unsigned int buttonpressed = results.value; //save the button code pressed
  Serial.println(results.value);//print the signal 
  function1(buttonpressed);
  res.resume();  //Continue
}
}
void function1 (unsigned int val)
{
if (val == num_1)
{if (num1_state == true)
  {digitalWrite(5,LOW); num1_state = (!num1_state);}
else {digitalWrite(5,HIGH); num1_state = (!num1_state);}
} 
if (val == num_4)
{if (num4_state == true)
  {digitalWrite(4,LOW); num4_state = (!num4_state);}
else {digitalWrite(4,HIGH); num4_state = (!num4_state);}
} 
if (val == num_3)
{if (num3_state == true)
  {digitalWrite(3,LOW); num3_state = (!num3_state);}
else {digitalWrite(3,HIGH); num3_state = (!num3_state);}
} 
if (val == num_2)
{if (num2_state == true)
  {digitalWrite(2,LOW); num2_state = (!num2_state);}
else {digitalWrite(2,HIGH); num2_state = (!num2_state);}
} 
if (val == num_5)
{if (num5_state == true)
  {digitalWrite(6,LOW); num5_state = (!num5_state);}
else {digitalWrite(6,HIGH); num5_state = (!num5_state);}
} 
if (val == num_6)
{
  for(int x = 0 ;x<5 ;x++)
  {
digitalWrite(7,HIGH);
delay(50);
digitalWrite(7,LOW);
delay(50);
  }
  }
}
