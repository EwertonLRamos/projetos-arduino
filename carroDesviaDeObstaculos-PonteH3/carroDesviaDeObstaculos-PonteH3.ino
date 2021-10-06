int buzzer = 4;

int Trig = 12;
int Echo = 13;

int vSpeedD = 90;
int vSpeedE = 100;

const int motorDF  = 2;    
const int motorDT  = 3;    
const int motorEF  = 5;   
const int motorET  = 6;   

void setup() 
{ 
  pinMode(buzzer, OUTPUT);
  pinMode(motorDF, OUTPUT);
  pinMode(motorDT, OUTPUT);
  pinMode(motorEF, OUTPUT);
  pinMode(motorET, OUTPUT);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);

  delay(3000);
}

void loop() 
{
  long duracion;
  long distancia;
  
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  duracion = pulseIn(Echo,HIGH);
  distancia = (duracion/2)/29;
  Serial.println(distancia);

  if(distancia < 15)
  {
    analogWrite(motorEF, 0);
    analogWrite(motorDF, 0);
    analogWrite(motorET, 0);
    analogWrite(motorDT, 0);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(50);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    if(distancia < 15)
    {
      analogWrite(motorEF, vSpeedE);
      analogWrite(motorDF, 0);
      analogWrite(motorET, 0);
      analogWrite(motorDT, vSpeedD);
      delay(500);

      analogWrite(motorEF, 0);
      analogWrite(motorDF, 0);
      analogWrite(motorET, 0);
      analogWrite(motorDT, 0);
      delay(250);
    } 
  }

  digitalWrite(buzzer, LOW);
  analogWrite(motorEF, vSpeedE);
  analogWrite(motorDF, vSpeedD);
  analogWrite(motorET, 0);
  analogWrite(motorDT, 0);
}
