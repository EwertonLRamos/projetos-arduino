#define azul 13
#define vermelho 12
#define buzzer 11
#define button 10

bool aux = true;
int tempo = 250; 

void setup() {

  pinMode(azul,OUTPUT);
  pinMode(vermelho,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {

  if(digitalRead(button) == HIGH){
    delay(5);
    if(digitalRead(button) == HIGH){
      aux = !aux;
    }
  }
  else{
    if(!aux){
      tempo = 125;  
      digitalWrite(vermelho, LOW);
      digitalWrite(azul, HIGH);
      tone(buzzer, 600);
      delay(tempo);
      digitalWrite(azul, LOW);
      digitalWrite(vermelho, HIGH);
      tone(buzzer, 500);
      delay(tempo);
    }
    if(aux){
      digitalWrite(vermelho, LOW);
      digitalWrite(azul, HIGH);
      tone(buzzer, 600);
      delay(tempo);
      digitalWrite(azul, LOW);
      digitalWrite(vermelho, HIGH);
      tone(buzzer, 500);
      delay(tempo);
    }   
  }
}
