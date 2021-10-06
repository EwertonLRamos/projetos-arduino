#define MotorLadoEsquerdo1 1
#define MotorLadoEsquerdo2  2

#define MotorLadoDireito1  3
#define MotorLadoDireito2 4


#define VelocidadeMotorLadoEsquerdo 11
#define VelocidadeMotorLadoDireito 10


int ValorVelocidadeMotorLadoEsquerdo = 100;
int ValorVelocidadeMotorLadoDireito = 100;

#define LEDsBrancos 8
#define LEDsVermelhos 13

void setup() 
{
  pinMode(MotorLadoEsquerdo1, OUTPUT);
  pinMode(MotorLadoEsquerdo2, OUTPUT);
  pinMode(MotorLadoDireito1, OUTPUT);
  pinMode(MotorLadoDireito2, OUTPUT);

  pinMode(LEDsBrancos, OUTPUT);
  pinMode(LEDsVermelhos, OUTPUT);

  delay(3000);
}

void loop() 
{
  digitalWrite(LEDsBrancos, HIGH);
  digitalWrite(LEDsVermelhos, HIGH);
  
  analogWrite(VelocidadeMotorLadoEsquerdo, ValorVelocidadeMotorLadoEsquerdo);
  analogWrite(VelocidadeMotorLadoDireito, ValorVelocidadeMotorLadoDireito);

  digitalWrite(MotorLadoEsquerdo1, LOW);
  digitalWrite(MotorLadoEsquerdo2, HIGH);

  digitalWrite(MotorLadoDireito1, LOW);
  digitalWrite(MotorLadoDireito2, HIGH);
}
