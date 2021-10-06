void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int pot = analogRead(2);
  Serial.println(pot);
}
