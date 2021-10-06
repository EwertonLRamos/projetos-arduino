const int pinoLed = 13; //PINO DIGITAL UTILIZADO PELO LED
const int pinoLDR = A5; //PINO ANALÓGICO UTILIZADO PELO LDR

int var = 0;
  
void setup(){  
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoLDR, INPUT); //DEFINE O PINO COMO ENTRADA

  Serial.begin(9600);
}    

void loop(){
  var = analogRead(pinoLDR);

  Serial.println(var);
  //O VALOR 600 PODE SER AJUSTADO
  if(var < 200) //SE O VALOR LIDO FOR MENOR QUE 600, FAZ
    digitalWrite(pinoLed, HIGH); //ACENDE O LED
  else //SENÃO, FAZ
    digitalWrite(pinoLed, LOW); //APAGA O LED  
}
