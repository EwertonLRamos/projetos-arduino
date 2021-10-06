#define potc A0

byte leds[] = {8,9,10,11};

int valorPot;

void setup() {
  for (int x = 0; x < leds.length(); x++){
    pinMode(leds[x], OUTPUT);
  }
}

void loop() {
  valorPot = analogRead(potc);
  
  if(valorPot >= 0){ 
    digitalWrite(leds[0], HIGH);
    
    if(valorPot >= 256){
      digitalWrite(leds[1], HIGH);
      
      if(valorPot >= 512){
        digitalWrite(leds[2], HIGH);
        
        if(valorPot >= 768){
          digitalWrite(leds[3], HIGH);
        
        } else {digitalWrite(leds[3], LOW);}         
      } else {digitalWrite(leds[2], LOW);}
    } else {digitalWrite(leds[1], LOW);}  
  } else {digitalWrite(leds[0], LOW);}
}
