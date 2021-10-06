#include <SoftwareSerial.h>

#define RX 0
#define TX 1
#define rele 2

SoftwareSerial bluetooth(RX, TX); 
 
void setup() 
{
  pinMode(rele , OUTPUT);
  digitalWrite(rele , HIGH);
  bluetooth.begin(9600);
}

void loop()
{
  if (bluetooth.available())
  {
     char dados = bluetooth.read();
     bluetooth.println(dados); 
     if (dados=='0')
     { 
        bluetooth.println("HIGH");
        digitalWrite(rele , HIGH);
     }
     else if (dados=='1')
     {
        bluetooth.println("LOW");
        digitalWrite(rele , LOW);
     }
  }                     
}
