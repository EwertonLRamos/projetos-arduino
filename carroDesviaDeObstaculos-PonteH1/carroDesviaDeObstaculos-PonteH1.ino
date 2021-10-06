// Define os pinos de utilização do Driver L298.
const int motorA1  = 9;    // Pin  5 of L293.
const int motorA2  = 3;    // Pin  6 of L293.
const int motorB1  = 11;   // Pin 10 of L293.
const int motorB2  = 10;   // Pin 9 of L293.

int vel = 200;   //0 < x < 255.

int trigger = 2;
int echo = 3;

void setup() 
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

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

  if(distance <= 5)
  {
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
    delay(500);
    if(distance <= 5)
    {
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 255);
      analogWrite(motorB1, 0);
      analogWrite(motorB2, 255);
      delay(1000);
    }
  }
  else
  {
    analogWrite(motorA1, 150);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 150);
    analogWrite(motorB2, 0);  
  }
}
