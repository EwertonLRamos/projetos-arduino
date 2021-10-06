#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int trigger = 2; 
int echo = 3; 
 
void setup() 
{
  Serial.begin(9600);
  lcd.init ();
  lcd.backlight();
  
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT); 
}
 
void loop() 
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
 
  int duration = pulseIn(echo, HIGH); 
  
  int distance = (duration/2) / 29.1; 
  
  lcd.setCursor(0,0);
  lcd.print("    Trena Digital   ");
  lcd.setCursor(0,1);
  lcd.print("Distancia: "); 
  lcd.print(distance);
  lcd.print("cm   ");

  Serial.println(distance);
  
  delay(100);
}
