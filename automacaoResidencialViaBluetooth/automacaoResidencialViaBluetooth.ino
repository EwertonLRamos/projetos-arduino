#include <SoftwareSerial.h>
#include <Servo.h>

#define RX 0
#define TX 1

#define servo1 6
#define servo2 7
#define servo3 8
#define servo4 9

Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;

SoftwareSerial bluetooth(RX, TX); 

char dados;
bool estados [10];
int releLeds [4] = {2, 3, 4, 5};
Servo servos [4] = {servoA, servoB, servoC, servoD};
 
void setup() {
  
  for(int i = 0; i < 4; i++) {
    pinMode(releLeds[i], OUTPUT);
    servos[i].write(0); //Ângulo do servo para fechar a janela
  }

  for (int i = 0; i < 10; i++)
     estados[i] = 0;
  
  servoA.attach(servo1);
  servoB.attach(servo2);
  servoC.attach(servo3);
  servoD.attach(servo4);
  
  bluetooth.begin(9600);
}

void loop() { 
           
  if (bluetooth.available()) {  
    dados = bluetooth.read();
    bluetooth.println(dados); 
    if (dados == 'i') {
      estados[8] = !estados[8];
      if(estados[8]) {
        for(int i = 0; i < 4; i++) {
          digitalWrite(releLeds[i], HIGH);
          servos[i].write(0); //Ângulo do servo para fechar a janela
        }
      }
    }
    else if (dados == 'j') {
      estados[9] = !estados[9];
      if(estados[9]) {
        for(int i = 0; i < 4; i++) {
          digitalWrite(releLeds[i], LOW);
          servos[i].write(90); //Ângulo do servo para abrir a janela
        }
      }
    }
    else {
      switch (dados) {
        case 'a':
          estados[0] = !estados[0];
          break; 
        case 'b':
          estados[1] = !estados[1];
          break;
        case 'c':
          estados[2] = !estados[2];
          break;
        case 'd':
          estados[3] = !estados[3];
          break;
        case 'e':
          estados[4] = !estados[4];
          break;
        case 'f':
          estados[5] = !estados[5];
          break;
        case 'g':
          estados[6] = !estados[6];
          break;
        case 'h':
          estados[7] = !estados[7];
          break;                  
      }
      for (int i = 0; i < 8; i++) {
        if (i <= 3)
          digitalWrite(releLeds[i], estados[i]); 
        else {
          int j = i - 4;
          if(estados[i])
            servos[j].write(90); //Ângulo do servo para abrir a janela
          else
            servos[j].write(0); //Ângulo do servo para fechar a janela
        } 
      }
    }
  }                     
}
