int cores[3] = {3, 2, 1};

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(cores[i], OUTPUT);
  }
}

void loop(){
  digitalWrite(cores[2], HIGH);
  delay(500); //Vermelho
  digitalWrite(cores[1], HIGH);
  delay(500); //Azul + Vermelho
  digitalWrite(cores[2], LOW);
  delay(500); //Azul
  digitalWrite(cores[0], HIGH);
  delay(500); //Azul + Verde
  digitalWrite(cores[1], LOW);
  delay(500); //Verde
  digitalWrite(cores[2], HIGH);
  delay(500); //Verde + Vermelho 
  //digitalWrite(cores[1], HIGH);
  //delay(500); //Verde + Azul + Vermelho
  digitalWrite(cores[0], LOW);
  digitalWrite(cores[1], LOW);
}
