int trigger = 2; //Variável Trigger(Emissor)
int echo = 3; //Variável Echo(Receptor) 
 
void setup() 
{
  Serial.begin(9600); //Inicio a conexão Serial
  
  pinMode(trigger, OUTPUT); //Indico que a porta vai ser de saída
  pinMode(echo, INPUT); //Indico que a porta vai ser de entrada
}
 
void loop() 
{ 
  digitalWrite(trigger, LOW);         //
  delayMicroseconds(2);               //
  digitalWrite(trigger, HIGH);        // Calculo da distância
  delayMicroseconds(10);              // baseado no intervalo de tempo
  digitalWrite(trigger, LOW);         //
  int duration = pulseIn(echo, HIGH); // 
  int distance = (duration/2) / 29.1; // 
  
  Serial.println(distance); //Escrevendo o valor da distância no monitor Serial
  delay(100);
}
