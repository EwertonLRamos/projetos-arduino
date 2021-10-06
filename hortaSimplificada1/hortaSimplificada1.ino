#define sensorDeUmidade A5
#define vermelhoLed 13
#define amareloLed 12
#define verdeLed 11
#define buzzer 10

int varSensorDeUmidade = 0;

void setup() {
  pinMode(vermelhoLed, OUTPUT);
  pinMode(amareloLed, OUTPUT);
  pinMode(verdeLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  varSensorDeUmidade = analogRead(sensorDeUmidade);
  Serial.println(varSensorDeUmidade);
  if(varSensorDeUmidade >= 800){
    digitalWrite(vermelhoLed, HIGH);
    digitalWrite(amareloLed, HIGH);
    digitalWrite(verdeLed, HIGH);
    tone(buzzer, 650);
    delay(500);
    noTone(buzzer);
    delay(500);
  } else if (varSensorDeUmidade >= 400) {
    digitalWrite(vermelhoLed, LOW);
    digitalWrite(amareloLed, HIGH);
    digitalWrite(verdeLed, HIGH);
  } else {
    digitalWrite(vermelhoLed, LOW);
    digitalWrite(amareloLed, LOW);
    digitalWrite(verdeLed, HIGH);
  }
}
