#define _do   262
#define _re   294
#define _mi   330
#define _fa   349
#define _sol  392
#define _la   440
#define _si   494
#define _do2  523
#define _re2  587
#define _mi2  659
#define _fa2  698
#define _sol2 783
#define _la2  880
#define _si2  987
#define _do3  1023

#define   b1  2
#define   b2  3
#define   b3  4
#define   b4  5
#define   b5  6
#define   b6  7
#define   b7  8
#define   b8  9

#define baux  10

int buzzer = 11;
int aux = 0;
 
int botoes[8] = {2, 3, 4, 5, 6, 7, 8, 9};

int melodias[2][8]{
  {_do , _re , _mi , _fa , _sol , _la , _si , _do2},
  {_do2, _re2, _mi2, _fa2, _sol2, _la2, _si2, _do3}
};

void setup(){
    pinMode(baux, INPUT);
  for(int i = 0; i < 8; i++){
    pinMode(botoes[i], INPUT);
  }
  Serial.begin(9600);
}

void loop(){
   if(digitalRead(baux) == HIGH){ 
    while(digitalRead(baux) == HIGH){
      for(int i = 0; i < 8; i++){
        if(digitalRead(botoes[i]) == HIGH){
          tone(buzzer, melodias[1][i], 50);
        }
      }
    }
  }
  else{
    for(int i = 0; i < 8; i++){
      while(digitalRead(botoes[i]) == HIGH){
        if(digitalRead(botoes[i]) == HIGH){
          tone(buzzer, melodias[0][i], 50);
        }
      }
    }
  }
}
