#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(3); 
 
void setup()
{
  // Define a velocidade maxima para os motores 1 e 2
  //motor1.setSpeed(255); 
  //motor2.setSpeed(255); 
}
 
void loop()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  delay(2000);

  motor1.setSpeed(0);
  motor1.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  delay(2000);

  motor1.setSpeed(255);
  motor1.run(BACKWARD); 
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  delay(2000);

  motor1.setSpeed(0);
  motor1.run(RELEASE); 
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  delay(2000);
 
}
