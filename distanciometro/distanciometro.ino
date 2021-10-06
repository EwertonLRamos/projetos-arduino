#define trigger1 2
#define echo1 3
#define trigger2 4
#define echo2 5
#define trigger3 6
#define echo3 7

#define buzzer 11

long tempo1;
long distancia1;
long tempo2;
long distancia2;
long tempo3;
long distancia3;

void setup(){
  
  pinMode(trigger1 , OUTPUT);
  pinMode(echo1 , INPUT);
  pinMode(trigger2 , OUTPUT);
  pinMode(echo2 , INPUT);
  pinMode(trigger3 , OUTPUT);
  pinMode(echo3 , INPUT);
  
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  
  digitalWrite(trigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger1, LOW);    
  tempo1 = pulseIn(echo1, HIGH);
  distancia1 = tempo1/29/2;
  
  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger2, LOW);  
  tempo2 = pulseIn(echo2, HIGH);
  distancia2 = tempo2/29/2;
  
  digitalWrite(trigger3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger3, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger3, LOW);    
  tempo3 = pulseIn(echo3, HIGH);
  distancia3 = tempo3/29/2;
  
  Serial.print("Sensor 1 - ");
  Serial.print(distancia1);
  Serial.print(" | ");

  Serial.print("Sensor 2 - ");
  Serial.print(distancia2);
  Serial.print(" | ");

  Serial.print("Sensor 3 - ");
  Serial.print(distancia3);
  Serial.println(" | ");

  if (distancia1 > 0.00 && distancia1 <= 15.00 ||
      distancia2 > 0.00 && distancia2 <= 15.00 ||
      distancia3 > 0.00 && distancia3 <= 15.00){ 
        
    delay(2000);

    digitalWrite(trigger1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger1, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger1, LOW);    
    long tempox = pulseIn(echo1, HIGH);
    long distanciax = tempox/29/2;
    
    digitalWrite(trigger2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger2, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger2, LOW);  
    long tempoy = pulseIn(echo2, HIGH);
    long distanciay = tempoy/29/2;
    
    digitalWrite(trigger3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger3, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger3, LOW);    
    long tempoz = pulseIn(echo3, HIGH);
    long distanciaz = tempoz/29/2;

    if (distanciax > 0.00 && distanciaz <= 15.00 ||
        distanciay > 0.00 && distanciay <= 15.00 ||
        distanciaz > 0.00 && distanciaz <= 15.00){
    
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
    
      delay(2000);
    }
  }
  else{ 
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
