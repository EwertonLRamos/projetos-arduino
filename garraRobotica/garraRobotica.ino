#include <Servo.h>

#define servoGarra 13
#define potGarra   A0

Servo garra;

int valorPotGarra;
int valorAngGarra;

void setup() {
  garra.attach(servoGarra);
}

void loop() {
  valorPotGarra = analogRead(potGarra);               
  valorAngGarra = map(valorPotGarra, 0, 1024, 0, 90);
  garra.write(valorAngGarra);
}
