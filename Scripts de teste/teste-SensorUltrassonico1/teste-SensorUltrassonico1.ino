#define led 13

int trigger = 11;
float echo = 9;

void setup() {
  pinMode(led, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigger, HIGH);       
  delayMicroseconds(10);             
  digitalWrite(trigger, LOW);        
  long duration = pulseIn(echo, HIGH); 
  double distancia = duration/58;

  Serial.print("Valor lido: ");
  Serial.print(distancia);
  Serial.println("cm");

  if(distancia < 20){
  digitalWrite(led, HIGH);
  } else {
  digitalWrite(led, LOW);  
  }
}
