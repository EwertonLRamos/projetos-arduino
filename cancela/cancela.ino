#include <Servo.h>

Servo cancela;

#define ledVermelho 13
#define ledVerde 12

#define servo 11

#define botaoSobe 10
#define botaoAbaixa 9

bool estado;

void setup() {
  cancela.attach(servo);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  
  pinMode(botaoSobe, INPUT);
  pinMode(botaoAbaixa, INPUT);

  cancela.write(0);
  digitalWrite(ledVermelho, HIGH);
}

void loop() {
  
  if(digitalRead(botaoSobe) == HIGH){
    delay(10);  
    if(digitalRead(botaoSobe) == HIGH){
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledVermelho, LOW);
      cancela.write(90);
    }
  }
  if(digitalRead(botaoAbaixa) == HIGH){
    delay(10);  
    if(digitalRead(botaoAbaixa) == HIGH){
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, HIGH);
      cancela.write(0);
    }
  }
}
