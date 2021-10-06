int vezesQueCireneToca = 0;
int vezesQueBipToca = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  while (vezesQueCireneToca<4) {
    for (int freq = 500; freq<2000; freq+=1) {
      tone(12,freq);
      delayMicroseconds(600);
    }
    ++vezesQueCireneToca;
    vezesQueBipToca = 0;
  }
  noTone(12);

  delay(2000);

  while (vezesQueBipToca<4) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);                    
    digitalWrite(LED_BUILTIN, LOW); 
    delay(1000);

    ++vezesQueBipToca;
    vezesQueCireneToca = 0;
  }

  delay(2000);
}
