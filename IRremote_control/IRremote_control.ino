#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

int state1=1;
int state2=1;
int state3=1;
int state4=1;
int state5=1;
int state6=1;
int state7=1;


int led1 =13;
int led2 =12;
int led3 =11;
int led4 =10;
int led5=9;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);  
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
 
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);    
    irrecv.resume(); // Receive the next value
  
    
    if(results.value == 0x38863BE0)
    {
     digitalWrite(led1,state1);
     state1 = !state1; 
    }
    if(results.value == 0x38863BD0)
    {
     digitalWrite(led2,state2);
     state2 = !state2; 
    }
    if(results.value == 0x38863BF0)
    {
     digitalWrite(led3,state3);
     state3 = !state3; 
    }
    if(results.value == 0x3838863BC8)
    {
     digitalWrite(led4,state4);
     state4 = !state4; 
    }
    if(results.value == 0x38863BE8)
    {
     digitalWrite(led5,state5);
     state5 = !state5; 
    }
    
    
    
  }   
  

}
