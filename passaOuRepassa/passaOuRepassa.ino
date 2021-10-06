#define bA 13
#define bV 6
#define bM 8

#define ledA 11
#define ledV 4

int eA = 0;
int eV = 0;
int eM = 0;

int contA = 0;
int contV = 0;

int trava = 0;

void setup(){
  pinMode(bA, INPUT);
  pinMode(bV, INPUT);
  pinMode(bM, INPUT);
  
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  eA = digitalRead(bA);
  eV = digitalRead(bV);
  eM = digitalRead(bM);

  //Serial.println(eA);
  //Serial.print(" | ");
  //Serial.println(eM);
  
  if((eA == 1)&&(trava == 0)){
    digitalWrite(ledA, HIGH);
    trava = 1;
    Serial.println("Amarelo");
  }
  if((eV == 1)&&(trava == 0)){
    digitalWrite(ledV, HIGH);
    trava = 1;
    Serial.println("Vermelho");
  }
  if(trava == 1){
    delay(5000);
    digitalWrite(ledA, LOW);
    digitalWrite(ledV, LOW);
    trava = 0;
    Serial.println("Reset");
  }
}
