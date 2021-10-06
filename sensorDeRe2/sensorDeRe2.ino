#include <NewPing.h>

#define trigger 6  
#define echo 7 
#define maxdistance 20
#define buzzer 5

int tempo;
int distancia;

NewPing ultrassonico(trigger, echo, maxdistance);

void setup() 
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  tempo = 10000000;
  distancia = ultrassonico.ping_cm();

  digitalWrite(buzzer, LOW);

  if(distancia <= 15 && distancia > 10)
  {
    tempo = 1000;
    digitalWrite(buzzer, HIGH);
    delay(tempo);
    digitalWrite(buzzer, LOW);
    delay(tempo);
  }    
  if(distancia <= 10 && distancia > 7)
  {
    tempo = 750;
    digitalWrite(buzzer, HIGH);
    delay(tempo);
    digitalWrite(buzzer, LOW);
    delay(tempo);
  }      
  if(distancia <= 7 && distancia > 4)
  {
    tempo = 500;
    digitalWrite(buzzer, HIGH);
    delay(tempo);
    digitalWrite(buzzer, LOW);
    delay(tempo);
  }         
  if(distancia <= 4 && distancia > 2)
  {
    tempo = 250;
    digitalWrite(buzzer, HIGH);
    delay(tempo);
    digitalWrite(buzzer, LOW);
    delay(tempo);
  }          
  if(distancia <= 2)
  {
    tempo = 50;
    digitalWrite(buzzer, HIGH);
    delay(tempo);
    digitalWrite(buzzer, LOW);
    delay(tempo);
  } 
  //tone(buzzer, 300, tempo);
  //delay(50);
  Serial.print(tempo);
  Serial.print(" ");
  Serial.println(distancia);
  }
