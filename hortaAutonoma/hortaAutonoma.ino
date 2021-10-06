#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;

#define rele 13

#define botaoDisplay 6

#define sensorDireita A3
#define sensorEsquerda A2

#define intervaloBotao 500
#define intervaloDisplay 500
#define limiteMillis 4320000000

bool dados = LOW;
bool estado = LOW;
int qtdIrrigacoes = 0;
int contadorMillis = 0;

int valSensorDireita = 0;
int valSensorEsquerda = 0;
float mediaValSensores = 0; 

unsigned long tempoAtual = 0;
unsigned long ultimaVezRele = 0;
unsigned long ultimaVezBotao = 0;
unsigned long ultimaVezDisplay = 0;

int intervaloIrrigacao = 2000;

LiquidCrystal_I2C lcd(0x3F,20,4);

void setup() {
  lcd.init();
  Serial.begin(9600);
  pinMode(botaoDisplay, INPUT);
  escreverMsgPadrao(HIGH);
  delay(3000);  
}

void loop() {
  tempoAtual = millis();
  
  valSensorDireita = analogRead(sensorDireita);
  valSensorEsquerda = analogRead(sensorEsquerda);

  mediaValSensores = (valSensorDireita + valSensorEsquerda) / 2;

  if(tempoAtual == limiteMillis)
    contadorMillis++;

  if(digitalRead(botaoDisplay)){
    if(tempoAtual - ultimaVezBotao >= intervaloBotao) {
      ultimaVezBotao = tempoAtual;
      if(digitalRead(botaoDisplay)){
        lcd.clear();
        dados = !dados;
      }
    }
  } else {   
    if(dados){
      if(tempoAtual - ultimaVezDisplay >= intervaloDisplay) {
        ultimaVezDisplay = tempoAtual;
        calcularEscreverDadosNoDisplay(qtdIrrigacoes, mediaValSensores, HIGH);
      }
    }
    if(mediaValSensores >= 800) {
      if(tempoAtual - ultimaVezRele >= intervaloIrrigacao){
        ultimaVezRele = tempoAtual;
        estado = !estado;
        if(estado) {
          qtdIrrigacoes++;
          intervaloIrrigacao = 2000;
          if(!dados)
            escreverAvisoDeIrrigacao(HIGH);
        } else {
          intervaloIrrigacao = 1000;
          if(!dados)
            escreverMsgPadrao(LOW);
        }
      }
      digitalWrite(rele, estado);
    } else {
      digitalWrite(rele, LOW);
      if(!dados)
        escreverMsgPadrao(LOW);
    }    
  }
}

void escreverAvisoDeIrrigacao(bool led) {
  ativarLedDisplay(led);

  lcd.setCursor(0, 0);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print("   Umidade baixa    ");
  lcd.setCursor(0, 2);
  lcd.print("    Irrigando...    ");
  lcd.setCursor(0, 3);
  lcd.print("                    ");
}

void calcularEscreverDadosNoDisplay(int qtdIrrigacoes, float umidadeGeral, bool led) {
  ativarLedDisplay(led);

  float litrosGastos = (qtdIrrigacoes * 0.05)/2;
  int percentualDeUmidade = map(umidadeGeral, 0, 1023, 100, 0);
    
  lcd.setCursor( 0, 0);
  lcd.print("   HORTA MADE BY!   ");
  lcd.setCursor( 0, 1);
  lcd.print("Irrigacoes:");
  lcd.setCursor(16, 1);
  lcd.print(qtdIrrigacoes);
  lcd.setCursor( 0, 2);
  lcd.print("Litros gastos:");
  lcd.setCursor(16, 2);
  lcd.print(litrosGastos);
  lcd.setCursor(19, 2);
  lcd.print("L");
  lcd.setCursor( 0, 3);
  lcd.print("Umidade:");
  lcd.setCursor(16, 3);
  lcd.print(percentualDeUmidade);
  lcd.setCursor(19, 3);
  lcd.print("%");
  
}

void escreverMsgPadrao(bool led) {
  ativarLedDisplay(led);
    
  lcd.setCursor(0, 0);
  lcd.print("********************");
  lcd.setCursor(0, 1);
  lcd.print("   Horta Robotica   ");
  lcd.setCursor(0, 2);
  lcd.print("      MADE BY       ");
  lcd.setCursor(0, 3);
  lcd.print("********************"); 
}

void ativarLedDisplay(bool led) {
  if(led)
    lcd.backlight();
  else
    lcd.noBacklight();
}
