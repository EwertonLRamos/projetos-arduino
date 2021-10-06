#define rele 6

void setup() {
  pinMode(13, OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop() {
  delay(30000);
  //digitalWrite(13, HIGH);
  for(int x = 0;x < 3; x++){
    digitalWrite(rele, HIGH);  
    delay(1000);               
    digitalWrite(rele, LOW);   
    delay(2500);
  }
  //digitalWrite(13,LOW);              
}
