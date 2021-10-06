#define ledVermelho 13
#define ledAmarelo 12
#define ledVerde 11
#define buzzer 10

int trigger = 9;  
float echo = 8; 

void setup() 
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() 
{
  digitalWrite(trigger, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigger, HIGH);       
  delayMicroseconds(10);             
  digitalWrite(trigger, LOW);        
  long duration = pulseIn(echo, HIGH); 
  double distancia = duration/58;

  digitalWrite(buzzer, HIGH);
    
  if(distancia <= 15 && distancia > 10)
  {
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(500);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  }    
  if(distancia <= 10 && distancia > 7)
  {
    digitalWrite(buzzer, LOW);
    delay(250);
    digitalWrite(buzzer, HIGH);
    delay(250);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
  }      
  if(distancia <= 7 && distancia > 4)
  {
    digitalWrite(buzzer, LOW);
    delay(125);
    digitalWrite(buzzer, HIGH);
    delay(125);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
  }         
  if(distancia <= 4 && distancia > 2)
  {
    digitalWrite(buzzer, LOW);
    delay(63);
    digitalWrite(buzzer, HIGH);
    delay(62);

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
  }          
  if(distancia <= 2)
  {
    digitalWrite(buzzer, LOW);
    delay(25);
    digitalWrite(buzzer, HIGH);
    delay(25);

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
  } 
}
