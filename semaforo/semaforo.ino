#define vermelho 13
#define amarelo 12
#define verde 11
#define vermelhoP 10
#define verdeP 9
#define buzzer 8

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelhoP, OUTPUT);
  pinMode(verdeP, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(vermelho, HIGH);
  digitalWrite(verdeP, HIGH);
  for(int cont = 1; cont <= 12; cont++){
    if(cont%2 == 1) 
      digitalWrite(buzzer, HIGH);
    else
      digitalWrite(buzzer, LOW);
    delay(250);
  }
  digitalWrite(vermelho, LOW);
  digitalWrite(verdeP, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelhoP, HIGH);
  delay(3000);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(1000);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelhoP, LOW);
}
