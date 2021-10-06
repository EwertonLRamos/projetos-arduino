int portas[7] = {2, 3, 4, 5, 6, 7, 8}; 
int score = 0;
int buzzer = 10;
int jogo = 12;

int portasm[10][7]
{
  //a-0, b-1, c-2, d-3, e-4, f-5, g-6 
  {portas[0], portas[1], portas[2], portas[3], portas[4], portas[5]},            //0
  {portas[1], portas[2]},                                                        //1
  {portas[0], portas[1], portas[3], portas[4], portas[6]},                       //2
  {portas[0], portas[1], portas[2], portas[3], portas[6]},                       //3
  {portas[1], portas[2], portas[5], portas[6]},                                  //4
  {portas[0], portas[2], portas[3], portas[5], portas[6]},                       //5
  {portas[0], portas[2], portas[3], portas[4], portas[5], portas[6]},            //6
  {portas[0], portas[1], portas[2]},                                             //7
  {portas[0], portas[1], portas[2], portas[3], portas[4], portas[5], portas[6]}, //8
  {portas[0], portas[1], portas[2], portas[5], portas[6]},                       //9
};

void apagar()
{
   for(int x = 0; x < 7; x++)
   {
     digitalWrite(portas[x] , HIGH);
   }
}

void animacao()
{
   for(int y = 0; y < 5; y++)
   {
      for(int x = 0; x < 6; x++)
      {
        digitalWrite(portas[x] , LOW);
        delay(100);
        apagar();
      }
   }
   digitalWrite(portas[6] , LOW);
   delay(500);
   apagar();
}

void setup() 
{
   for(int x = 0; x < 7; x++)
   {
     pinMode(portas[x], OUTPUT);
   }
   pinMode(buzzer, OUTPUT);
   pinMode(jogo, INPUT);

   digitalWrite(buzzer , HIGH);
   
   apagar();
   animacao();
}

void loop() 
{
  while(score <= 9)
  {
    if(digitalRead(jogo) == HIGH)
    {
      delay(200);
      score++;
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
    }
    apagar();
    for(int x = 0; x < 7; x++)
    {
      digitalWrite(portasm[score][x] , LOW);
    }
  }
  apagar();
  digitalWrite(buzzer, LOW);
  animacao();
  digitalWrite(buzzer, HIGH);
  score = 0;
}
