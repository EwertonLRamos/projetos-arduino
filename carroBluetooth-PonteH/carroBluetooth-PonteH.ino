#include <SoftwareSerial.h>

#define RX 0
#define TX 1

SoftwareSerial bluetooth(RX, TX);

const int motorA1  = 5;    
const int motorA2  = 4;   
const int motorB1  = 3;   
const int motorB2  = 2;   

const int buzzer =  6;

char dados;

void setup() 
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  /*if (bluetooth.available())
  {
    dados = bluetooth.read();
    bluetooth.println(dados);
    Serial.println(dados); 
    if (dados=='0')
    { 
      analogWrite(motorA1, HIGH); 
      analogWrite(motorA2, LOW);
      analogWrite(motorB1, HIGH);    
      analogWrite(motorB2, LOW);
      
      bluetooth.println("PARA FRENTE");
      Serial.println("PARA FRENTE");
    }
    else if (dados=='2')
    {
      analogWrite(motorA1, LOW); 
      analogWrite(motorA2, HIGH);
      analogWrite(motorB1, LOW);    
      analogWrite(motorB2, HIGH);
       
      bluetooth.println("PARA TRÁS");
      Serial.println("PARA TRÁS");
    }
    else if (dados=='1')
    {
      analogWrite(motorA1, LOW); 
      analogWrite(motorA2, HIGH);
      analogWrite(motorB1, HIGH);    
      analogWrite(motorB2, LOW);
      
      bluetooth.println("PARA ESQUERDA");
      Serial.println("PARA ESQUERDA");
    }
    else if (dados=='3')
    {
      analogWrite(motorA1, HIGH); 
      analogWrite(motorA2, LOW);
      analogWrite(motorB1, LOW);    
      analogWrite(motorB2, HIGH);
      
      bluetooth.println("PARA DIREITA");
      Serial.println("PARA DIREITA");
    }
    else if (dados=='4')
    {
      analogWrite(motorA1, HIGH); 
      analogWrite(motorA2, HIGH);
      analogWrite(motorB1, HIGH);    
      analogWrite(motorB2, HIGH);
      
      bluetooth.println("PARAR");
      Serial.println("PARAR");
    }
  }
  else
  {
    analogWrite(motorA1, HIGH); 
    analogWrite(motorA2, HIGH);
    analogWrite(motorB1, HIGH);    
    analogWrite(motorB2, HIGH);
    
    bluetooth.println("BLUETOOTH DESCONECTADO");
    Serial.println("BLUETOOTH DESCONECTADO");
  }
  if (bluetooth.available())
  {
    delay(50);
    if (bluetooth.available())
    {
      dados = bluetooth.read();
      bluetooth.println(dados);
      Serial.println(dados); 
    } 
  }
  else
  {
    analogWrite(motorA1, HIGH); 
    analogWrite(motorA2, HIGH);
    analogWrite(motorB1, HIGH);    
    analogWrite(motorB2, HIGH);
    
    bluetooth.println("BLUETOOTH DESCONECTADO");
    Serial.println("BLUETOOTH DESCONECTADO");
  }*/

  delay(50);
  dados = bluetooth.read();
  bluetooth.println(dados);
  Serial.println(dados);
  
  if (dados=='0')
  { 
    while(!bluetooth.available())
    {
      digitalWrite(motorA1, HIGH); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);    
      digitalWrite(motorB2, LOW);
     
      bluetooth.println("PARA FRENTE");
      Serial.println("PARA FRENTE");
    }
  }
  if (dados=='2')
  {
    while(!bluetooth.available())
    {
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);    
      digitalWrite(motorB2, HIGH);
     
      bluetooth.println("PARA TRÁS");
      Serial.println("PARA TRÁS");
    }
  }
  if (dados=='1')
  {
    while(!bluetooth.available())
    {
      digitalWrite(motorA1, LOW); 
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, HIGH);    
      digitalWrite(motorB2, LOW);
     
      bluetooth.println("PARA ESQUERDA");
      Serial.println("PARA ESQUERDA");
    }
  }
  if (dados=='3')
  {
    while(!bluetooth.available())
    {
      digitalWrite(motorA1, HIGH); 
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);    
      digitalWrite(motorB2, HIGH);
     
      bluetooth.println("PARA DIREITA");
      Serial.println("PARA DIREITA");
    }
  }
  if (dados=='4')
  {
    while(!bluetooth.available())
    {
      digitalWrite(motorA1, HIGH); 
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, HIGH);    
      digitalWrite(motorB2, HIGH);
     
      bluetooth.println("PARAR");
      Serial.println("PARAR");
    }
  }
}  
