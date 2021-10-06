#include <SoftwareSerial.h>

#define RX 0
#define TX 1

SoftwareSerial bluetooth(RX, TX);

int pinoSensorLuz = A0;
int pinoBuzzer = 2;               
int valorLuz = 0;                      
 
void setup()
{        
    pinMode(pinoBuzzer,OUTPUT);
    bluetooth.begin(9600);
    Serial.begin(9600);
}
 
void loop()
{
  valorLuz = analogRead(pinoSensorLuz);
  Serial.println(valorLuz);        
  if(valorLuz<500)
  {   
    bluetooth.println("ATENÇÃO: Invasor detectado!");             
    //for(int x = 0; x < 5; x++)
    //{
       digitalWrite(pinoBuzzer, HIGH);
       delay(100);
       digitalWrite(pinoBuzzer, LOW);
       delay(100);
    //}
  }
  else
  {                    
    digitalWrite(pinoBuzzer, LOW);
  }
  delay(10);                 
}
