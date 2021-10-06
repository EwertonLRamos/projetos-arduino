#include <NewPing.h>

#define echo A1
#define trigger A0

long duration;
long distance;

const int motorA1  = 5;    
const int motorA2  = 6;   
const int motorB1  = 9;   
const int motorB2  = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 
  
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  delay(3000);
}

void loop() {
  digitalWrite(trigger, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigger, HIGH);       
  delayMicroseconds(10);             
  digitalWrite(trigger, LOW);        
  duration = pulseIn(echo, HIGH); 
  distance = (duration/2) / 29.1;
  
  Serial.println(distance); 

  if(distance <= 10){
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
    delay(500);
    if(distance <= 10){
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 150);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, 125);
      delay(300);
    }
  }
  else{
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 200);
    analogWrite(motorB1, 175);
    analogWrite(motorB2, 0);  
  }
}
