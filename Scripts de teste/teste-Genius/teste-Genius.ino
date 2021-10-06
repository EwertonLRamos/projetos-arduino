#define buzzer 6

int pinosBotoes[4] = {2, 3, 4, 5}; 
int pinosLEDs [4] = {7, 8, 9, 10};
int botaoPressionado = 0;

void setup() {
  Serial.begin(9600);

  for(int x = 0; x <= 3; x++){
    pinMode(pinosBotoes[x], INPUT);
    pinMode(pinosLEDs[x], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {

  for(int x = 0; x <= 3; x++) {
    if(digitalRead(pinosBotoes[x]) == HIGH){
      botaoPressionado = pinosBotoes[x];
      
      Serial.println(botaoPressionado);
      digitalWrite(pinosLEDs[x], HIGH);
      tone(buzzer, 500);
      delay(500);
      digitalWrite(pinosLEDs[x], LOW);
      noTone(buzzer);
      break;
    }
  }
}
