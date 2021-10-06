#include <NewPing.h>
#include <LiquidCrystal.h>

#define trigger 10  
#define echo 9  
#define maxdistance 8
#define motor 2

int distancia = 0;
int contador = 0;

NewPing hcsr04(trigger, echo, maxdistance);
LiquidCrystal lcd(3, 4, 5, 6, 7, 8); 
 
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(motor, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("    Projeto     ");
  lcd.setCursor(0,1);
  lcd.print("ESTEIRA MECANICA");
  delay(2000);
  lcd.clear();
}
 
void loop() 
{
  distancia = hcsr04.ping_cm();

  digitalWrite(motor, HIGH);
  
  if(distancia < 6 && distancia > 2)
  {
    delay(600);
    if(distancia < 6 && distancia > 2)
    {
      delay(50);
      if(distancia < 6 && distancia > 2)
      {
        delay(50);
        if(distancia < 6 && distancia > 2)
        {
          delay(50);
          if(distancia < 6 && distancia > 2)
          {
            contador++;
          }
        }
      }
    }
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Projeto da esteira   ");
  lcd.setCursor(0, 1);
  lcd.print("Qtd. itens:");
  lcd.print(contador);

  Serial.println(distancia);
}
