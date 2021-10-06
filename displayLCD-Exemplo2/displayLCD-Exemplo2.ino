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
  lcd.print("    Made By!    ");
  delay(1000);
  lcd.clear();
  delay(1000);
}
