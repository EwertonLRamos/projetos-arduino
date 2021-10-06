#define buzzer 11

int pinosBotoes[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; 
int botaoPressionado = 0;

void setup() {
  Serial.begin(9600);

  for(int x = 0; x <= 9; x++){
    pinMode(pinosBotoes[x], INPUT);
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {

  for(int x = 0; x <= 9; x++) {
    if(digitalRead(pinosBotoes[x]) == HIGH){
      botaoPressionado = pinosBotoes[x];
      Serial.println(botaoPressionado);
      tone(buzzer, 500);
      delay(500);
      noTone(buzzer);
      break;
    }
  }
}
