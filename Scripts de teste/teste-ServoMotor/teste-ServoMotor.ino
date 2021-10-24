#include <Servo.h>

Servo servo;

#define pinServo 10

void setup() {
  servo.attach(pinServo);

  //servo.write(85);
  //delay(500);
  //servo.write(170);
  //delay(500);
  //servo.write(85);
  //delay(500);
}

void loop() {
  //for(int x = 180; x > 90; x--){
  //  servo.write(x);
  //  delay(5);
  //}
  //for(int x = 90; x < 180; x++){
  //  servo.write(x);
  //  delay(5);
  //}
  
  servo.write(180);
  //delay(500);
  //servo.write(180);
  //delay(500);
}
