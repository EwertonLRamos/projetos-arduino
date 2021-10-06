#include <SoftwareSerial.h>

#define RX 0
#define TX 1
#define rele 2
#define som 3

bool aux;

SoftwareSerial bluetooth(RX, TX); 
 
void setup() 
{
  pinMode(rele , OUTPUT);
  pinMode(som, INPUT);
  digitalWrite(rele , HIGH);
  bluetooth.begin(9600);
  aux = false;
}

void loop()
{
  if(digitalRead(som))
  {
    aux = !aux;
    if(aux)
    {
      bluetooth.println("Lâmpada ligada!");
    }
    else
    {
      bluetooth.println("Lâmpada desligada!");
    }  
  }
  digitalWrite(rele, aux);                     
}
