byte pinosLed[] = {0,1,2,3,4,5,10,12,13,14};
int potenciometro = A0;
int valor = 0;

void setup() 
{
  for (int x = 0; x < 10; x++)
  {
    pinMode(pinosLed[x], OUTPUT);
  }
}

void loop() 
{
  for(int x = 0; x < 10; x++)
  {
    digitalWrite(pinosLed[x], HIGH);
    delay(500);
    digitalWrite(pinosLed[x], LOW);
  }
  for(int x = 10; x > 0; x--)
  {
    digitalWrite(pinosLed[x], HIGH);
    delay(500);
    digitalWrite(pinosLed[x], LOW);
  }
   /*valor = analogRead(potenciometro);
   if(valor == 0)
   {
     for(int b = 0; b < 10; b++)
     {
        digitalWrite(pinosLed[b], LOW);
     }
   }
   else if(valor > 0)
   {
     digitalWrite(pinosLed[0], HIGH);
     for(int a = 1; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   } 
   else if(valor > 123 && valor <= 247)
   {
     for(int b = 0; b < 2; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 2; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }
   else if(valor > 247 && valor <= 371)
   {
     for(int b = 0; b < 3; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 3; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }
   else if(valor > 371 && valor <= 495)
   {
     for(int b = 0; b < 4; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 4; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   } 
   else if(valor > 495 && valor <= 619)
   {
     for(int b = 0; b < 5; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 5; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }  
   else if(valor > 619 && valor <= 743)
   {
     for(int b = 0; b < 6; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 6; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }
   else if(valor > 743 && valor <= 867)
   {
     for(int b = 0; b < 7; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 7; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }
   else if(valor > 867 && valor <= 991)
   {
     for(int b = 0; b < 8; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
     for(int a = 8; a < 10; a++)
     {
        digitalWrite(pinosLed[a], LOW);
     }
   }
   else
   {
     for(int b = 0; b < 10; b++)
     {
        digitalWrite(pinosLed[b], HIGH);
     }
   }*/
}
