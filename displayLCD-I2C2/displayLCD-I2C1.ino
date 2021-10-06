//Olhar este site: https://www.usinainfo.com.br/blog/projeto-arduino-com-display-lcd-e-adaptador-i2c/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
 
void setup(){
 lcd.init ();
}
 
void loop(){
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Arduino e Cia !!");
  lcd.setCursor(0,1);
  lcd.print("LCD e modulo I2C");
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);
}
