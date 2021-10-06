#include <Stepper.h>

const int stepsPerRevolution = 64;

Stepper myStepper1(stepsPerRevolution,  2,  4,  3,  5);
Stepper myStepper2(stepsPerRevolution, 10, 11, 12, 13);

void moverMotor (int vel, int sentido){
  myStepper1.setSpeed(vel);
  myStepper2.setSpeed(vel);
  for(int x = 0;x < 32; x++)
  {
    myStepper1.step(stepsPerRevolution * sentido);
    myStepper2.step(stepsPerRevolution * sentido);
  }
}

void setup() {
  
}

void loop() {
  moverMotor(500,1);
  delay(1000);
  moverMotor(500,-1);
  delay(1000);
  moverMotor(500,0);
  delay(1000);
}
