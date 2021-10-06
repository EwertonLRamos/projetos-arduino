#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
 
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}
 
void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("  Display LCD!  ");
  lcd.setCursor(0,1);
  lcd.print("Coloque seu nome");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Display  LCD  ");
  lcd.setCursor(0,1);
  lcd.print("      16x2      ");
  delay(2000);
  lcd.clear();
}
