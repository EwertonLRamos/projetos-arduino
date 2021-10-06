#define porta_rele1 2
#define porta_rele2 3
#define porta_rele3 4
#define porta_rele4 5
  
void setup()
{
  //Define pinos para o rele como saida
  pinMode(porta_rele1, OUTPUT); 
  pinMode(porta_rele2, OUTPUT);
  pinMode(porta_rele3, OUTPUT); 
  pinMode(porta_rele4, OUTPUT);
}
   
void loop()
{
  digitalWrite(porta_rele1, LOW);  //Liga rele 1
  digitalWrite(porta_rele2, HIGH); //Desliga rele 2
  digitalWrite(porta_rele3, LOW);  //Liga rele 3
  digitalWrite(porta_rele4, HIGH); //Desliga rele 4
  delay(2000);
  digitalWrite(porta_rele1, HIGH); //Desliga rele 1
  digitalWrite(porta_rele2, LOW);  //Liga rele 2
  digitalWrite(porta_rele3, HIGH); //Desliga rele 3
  digitalWrite(porta_rele4, LOW);  //Liga rele 4
  delay(2000);
}
