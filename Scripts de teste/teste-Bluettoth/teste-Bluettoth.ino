#include <SoftwareSerial.h>

#define RX 0
#define TX 1

SoftwareSerial bluetooth(RX, TX); 
 
void setup() 
{
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if (bluetooth.available())
  {
     char dados = bluetooth.read();
     bluetooth.println(dados);
     Serial.println(dados); 
     if (dados=='0')
     { 
        bluetooth.println("HIGH");
        Serial.println("HIGH");
     }
     else if (dados=='1')
     {
        bluetooth.println("LOW");
        Serial.println("LOW");
     }
  }                     
}
