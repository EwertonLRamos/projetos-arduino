/*******************************************************************************/
/*                Base de code pour le TP Jouons un peu                        */
/*               Paradigme de programmation procedurale                        */
/*                      2020 Regis KOLLY MLK/ECST                              */
/*               Fichier Excel pour générer le code CGRAM                      */
/*                        à cette adresse :                                    */
/*                                                                             */
/* http://stiddsin.free.fr/explorer/Cours-TD-TP/07c-Jouons-un-peu-Arduino.xlsx */
/*                                                                             */
/*******************************************************************************/


#define facilite 100       // 0: início difícil - 100: início fácil
#define nbDeCasesASauter 3 // Representa o comprimento possível do salto do dinossauro. Quanto mais tempo, mais fácil é 
#define limiteGauche 1     // Controle deslizante esquerdo de espessura sensível a dinossauros
#define limiteDroite 2     // Controle deslizante direito de espessura sensível a dinossauros
#define nombreNote 38      // Número de notas da frase musical (ver tabela de notas)
#define longueurNote 2     // Comprimento da nota musical (duração) em múltiplos de um loop
#define bas 0
#define haut 1

#define boutonJump A0
#define speaker 12
#define RESET 11

#define sp Serial.print
#define spln Serial.println

// Notas musicais
// A proporção das frequências de duas notas para a oitava é 2.
// 12 semitons em uma oitava. 
// A razão de frequência de dois semitons é 2=r^12
// r = décima segunda raiz de 2
const float r = pow(2,1.0/12); // r=1,059463094359295
const float DO2  = 130.81;
const float RE2  = 146.83;
const float MI2  = 164.81;
const float FA2  = 174.61;
const float SOL2 = 196.0;
const float LA2  = 220.0;
const float SI2  = 246.94;
const float DO3  = 261.63; 
const float RE3  = 293.66;
const float MI3  = 329.63;
const float FA3  = 349.23;
const float FA3d = 369.99;
const float SOL3 = 392.0;   // ou SOL3 = LA3 / r / r porque dois semitons entre SOL3 e LA3
const float LA3  = 440.0;
const float SI3  = 493.88;  // ou SI3 = LA3 * r * r porque dois semitons entre LA3 e SI3
const float DO4  = 523.25;
const float RE4  = 587.33;
const float MI4  = 659.29;
const float FA4  = 698.46;
const float SOL4 = 783.99;
const float LA4  = 880.0;
const float SI4  = 987.77;
const float DO5  = 1046.5;
const float RE5  = 1174.7;
const float MI5  = 1318.5;
const float FA5  = 1396.9;
const float SOL5 = 1568.0;
const float musique[nombreNote] = {RE3,SI2,RE3,SOL2,RE3,SI2,RE3,SOL2,RE3,SI2,RE3,SOL2,MI3,DO3,MI3,SOL2,MI3,DO3,MI3,SOL2,MI3,DO3,MI3,SOL2,FA3d,SOL3,SOL3,SOL3,FA3d,MI3,RE3,RE3,RE3,SI2,SOL2,SOL2,SOL2,SOL2};


#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(){
  Serial.begin(38400);

  pinMode(speaker,OUTPUT);
  lcd.begin(16,2);
  // Geração de uma nova sequência aleatória graças a uma entrada analógica sem fio
  randomSeed(analogRead(1)); // analogRead (1) é um valor aleatório devido ao ruído na entrada sem fio

  for(int i = 0; i < 2; i++){
    if(analogRead(boutonJump) >= 750){
      lcd.setCursor(0,0);
      lcd.print("     Vamos la     ");
      lcd.setCursor(0,1);
      lcd.print("      pessoal     ");
      delay(500);
      lcd.clear();
      delay(200);
      if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750)
        break;
    }
  }

  for(int i = 0; i < 3; i++){
    if(analogRead(boutonJump) >= 750){
      lcd.setCursor(0,0);
      lcd.print("  Aperte o botao  ");
      lcd.setCursor(0,1);
      lcd.print("    para pular    ");
      delay(500);
      lcd.clear();
      delay(200);
      if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750)
        break;
    }
  }  

  lcd.setCursor(16,0);
  lcd.print("Vamos Jogar");
  lcd.setCursor(21,1);
  lcd.print("Mas nao muito");
  // Rolando a mensagem
  for (int positionCounter = 0; positionCounter < nombreNote; positionCounter++) {
    if(analogRead(boutonJump) >= 750){
      tone(speaker,musique[positionCounter]);
      lcd.scrollDisplayLeft();
      delay(250); 
      if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750)
        break;
    }
  }
  
  noTone(speaker); // Cortamos a música no final da cutscene do jogo
  // Armazenamento de pictogramas CGRAM
  // Chamada da função que gera os pictogramas criados a partir do arquivo Excel
  // http://stiddsin.free.fr/explorer/Cours-TD-TP/07c-Jouons-un-peu-Arduino.xlsx
  CGRAM();
  lcd.clear();
  delay(1000);
  afficheScore(0); // Exibição de pontuação em 0
}

void loop(){
  // Variáveis ​​locais e locais estáticas
  bool positionPerso;           // Posição do personagem para cima ou para baixo
  int positionCible1;           // A posição pode eventualmente se tornar negativa
  int positionCible2;
  static bool memoBouton=0;     // Para memorizar o salto. Inicializado apenas uma vez (estático)
  static byte longueurSaut=0;   // Para memorizar o salto. Inicializado apenas uma vez (estático)
  static unsigned int boucle=0; // Número de loops. Deve ser inicializado uma vez (estático).
  static unsigned int score=0;  // Marcar pontos. Deve ser inicializado uma vez (estático). 
  
  if(!memoBouton){
    tone(speaker,musique[(boucle/longueurNote)%(nombreNote-1)]);   // desdobramento de todas as notas (módulo numberNote-1) em cada loop lengthNote *. Uma nota por duração de um problema.
  }
    // Redundância da função acceleration () para melhorar a jogabilidade (não perca o suporte durante o tempo limite do software)
  acceleration();  // Atraso gradual do jogo
  if(memoBouton==0){  // Leitura do pedido de salto apenas se o dinossauro já estiver caído no chão (caso contrário, ele sempre pode ficar para cima)
    if(analogRead(boutonJump) >= 50 && analogRead(boutonJump) < 150)
      memoBouton = 1;
  }
  if(memoBouton && longueurSaut<=nbDeCasesASauter){    // Limitação do comprimento do salto para o valor constante nbDeCasesASauter
    tone(speaker,(musique[(boucle/longueurNote)%(nombreNote-1)])*2); // Aumente a nota uma oitava (frequência * 2) durante o salto para se divertir
    positionPerso=haut;
    longueurSaut=longueurSaut+1;
  }
  else{
    positionPerso=bas;
    longueurSaut=0;
    memoBouton=0; // Nós derrubamos o dinossauro. Será necessário pressionar novamente para pular novamente
  }
  affichePersonnage(0,positionPerso); // Exibição de dinossauros na parte superior ou inferior. Primeiro parâmetro para possível evolução: avanço do dinossauro
  // Redundância da função acceleration () para melhorar a jogabilidade (não perca o suporte durante o tempo limite do software)
  acceleration();  // Atraso gradual do jogo
  if(memoBouton==0){  // Leitura do pedido de salto apenas se o dinossauro já estiver caído no chão (caso contrário, ele sempre pode ficar para cima)
    if(analogRead(boutonJump) >= 50 && analogRead(boutonJump) < 150)
      memoBouton = 1;
  }
  // Défilement du décor
  positionCible1=cible1(positionPerso); // Déplacement du cactus 1
  positionCible2=cible2(positionPerso); // Déplacement du cactus 2

  // Ordre important pour fluidifier : le && est une évaluation paraisseuse
  while(!memoBouton && ((positionCible1<=limiteDroite && positionCible1>=limiteGauche) || (positionCible2<=limiteDroite && positionCible2>=limiteGauche))){ // Dinosaure en bas et cactus présent
    gameOver(); // Si collision alors game over
  }
  // évaluation de l'évolution du score : grand cactus 2 ponts, petit cactus 1 point
  if(memoBouton && ((positionCible1<=(limiteGauche+1) && positionCible1>=limiteGauche) || (positionCible2<(limiteGauche+1) && positionCible2>=limiteGauche))){
    score=score+1;
    afficheScore(score);   // Affiche le score
  }  
  // Redondance de la fonction acceleration() pour améliorer la jouabilité (ne pas louper d'appui pendant la temporisation logicielle)
  acceleration();  // temporisation graduelle du jeu
  if(memoBouton==0){  // Leitura do pedido de salto apenas se o dinossauro já estiver caído no chão (caso contrário, ele sempre pode ficar para cima)
      if(analogRead(boutonJump) >= 50 && analogRead(boutonJump) < 150)
        memoBouton = 1;
  }
  boucle=boucle+1; // Compteur de boucle
}



/***************** CGRAM ******************/
/** creation des pictogramme dans le LCD **/
/******************************************/

// Coller la fonction CGRAM ci-dessous
void CGRAM(void){                                                  
  byte pictogramme0[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme0                                                  
    0,  0,  0,  0,  4,  6,  7,  7                                   
  };                                                  
  byte pictogramme1[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme1                                                  
    0,  0,  0,  0,  0,  0,  0,  17                                    
  };                                                  
  byte pictogramme2[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme2                                                  
    7,  13, 15, 15, 15, 15, 31, 31                                    
  };                                                  
  byte pictogramme3[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme3                                                  
    30, 31, 31, 31, 16, 30, 0,  0                                   
  };                                                  
  byte pictogramme4[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme4                                                  
    3,  1,  0,  0,  0,  0,  0,  0                                   
  };                                                  
  byte pictogramme5[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme5                                                  
    31, 31, 31, 31, 15, 6,  2,  3                                   
  };                                                  
  byte pictogramme6[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme6                                                  
    31, 30, 30, 28, 24, 16, 16, 24                                    
  };                                                  
  byte pictogramme7[8] = {  //  Création d’un tableau de 8 octets nommé pictogramme7                                                  
    24, 8,  0,  0,  0,  0,  0,  0                                   
  };                                                  
  lcd.createChar(0, pictogramme0); //  Écriture en CGRAM du pictogramme 0                                                 
  lcd.createChar(1, pictogramme1); //  Écriture en CGRAM du pictogramme 1                                                 
  lcd.createChar(2, pictogramme2); //  Écriture en CGRAM du pictogramme 2                                                 
  lcd.createChar(3, pictogramme3); //  Écriture en CGRAM du pictogramme 3                                                 
  lcd.createChar(4, pictogramme4); //  Écriture en CGRAM du pictogramme 4                                                 
  lcd.createChar(5, pictogramme5); //  Écriture en CGRAM du pictogramme 5                                                 
  lcd.createChar(6, pictogramme6); //  Écriture en CGRAM du pictogramme 6                                                 
  lcd.createChar(7, pictogramme7); //  Écriture en CGRAM du pictogramme 7                                                 
}                                                 



/************* AFFICHEPERSONNAGE **************/
/***** récupère la position haut ou bas *******/
/***** récupère x pour evolution LEVEL  *******/
/**********************************************/

// Fonction affichePersonnage
void affichePersonnage(byte x,bool y){
  if(y==bas){
//    tone(speaker,220);
    lcd.setCursor(x,0);         // Curseur (x POUR DIFFICULTE)*************************
    lcd.write((unsigned char)0);// Affichage du pictogramme 0 : la queue
    lcd.write(1);               // Affichage du pictogramme 1 : queue et cou
    lcd.write(2);               // Affichage du pictogramme 2 : l'œil
    lcd.write(3);               // Affichage du pictogramme 3 : la bouche
    lcd.setCursor(x,1);         // Curseur
    lcd.write(4);               // Affichage du pictogramme 4 : début de la queue
    lcd.write(5);               // Affichage du pictogramme 5 : jambe gauche
    lcd.write(6);               // Affichage du pictogramme 6 : jambe droite
    lcd.write(7);               // Affichage du pictogramme 7 : le bras
  }
  else{
//    tone(speaker,440);
    lcd.setCursor(x,1);         // Curseur
    lcd.print(" ");             // effacement en bas du début de la queue
    lcd.print(" ");             // effacement en bas de la jambe gauche
    lcd.print(" ");             // effacement en bas de la jambe droite
    lcd.print(" ");             // effacement en bas du bras
    lcd.setCursor(x,0);         // Curseur
    lcd.write(4);               // Affichage du pictogramme 4 : début de la queue
    lcd.write(5);               // Affichage du pictogramme 5 : jambe gauche
    lcd.write(6);               // Affichage du pictogramme 6 : jambe droite
    lcd.write(7);               // Affichage du pictogramme 7 : le bras
  } 
}



/************** CIBLES ************* */
/* retourne le curseur x de la cible */
/** int car x peut devenir négatif ***/
/*************************************/

int cible1(bool PersoHaut){
  static int x=random(15,20); // Apparition aléatoire. x peut être négative
  lcd.setCursor(x,1);
  if(x>3){
    lcd.print(" ");      // Effacement rémanence
  }
  else if(x<=3 && !PersoHaut){
    lcd.write((unsigned char)x+4); // Réécriture du bas du dyno
  }
  if(x>=0){
    x=x-1;
    lcd.setCursor(x,1);
    lcd.write(221);  // Affichage du caractère prédéfini le cactus1
  }
  else{
    x=random(15,20); // Apparition aléatoire
  }
  return x;
}

int cible2(bool PersoHaut){
  static int x=random(25,30); // Apparition aléatoire. x peut être négative
  lcd.setCursor(x,1);
  if(x>3){
    lcd.print(" ");      // Effacement rémanence
  }
  else if(x<=3 && !PersoHaut){
    lcd.write((unsigned char)x+4); // Réécriture du bas du dyno
  }
  if(x>=0){
    x=x-1;
    lcd.setCursor(x,1);
    lcd.write(243);  // Affichage du caractère prédéfini le cactus2
  }
  else{
    x=random(25,30); // Apparition aléatoire
  }
  return x;
}


/******* AFFICHESCORE *******/
/*** récupère et affiche  ***/
/*******  le score **********/
/****************************/

void afficheScore(int score){
  lcd.setCursor(6,0);
  lcd.print("Score:");
  if(score<10){     // Affichage des 0 non significatifs
    lcd.print("00"); // pour formater les score à 3 digits ex : 008 
  }
  else if(score<100){
    lcd.print("0");
  }
  lcd.print(score);
}


/************ NOUVELLEPARTIE ************/
/**** il faut une résistance entre ******/
/******* la broche 12 et Reset **********/
/****************************************/

void nouvellePartie(void) 
{
  for(;;){
    lcd.clear();
    lcd.setCursor(0,0),
    lcd.print("   New Game!!   ");
    lcd.setCursor(0,1),
    lcd.print("  Press Reset   ");
    delay(500);
    lcd.clear();
    delay(200);
  }
}


/************ GAMEOVER ************/
/**** affiche game over ***********/
/******* et appelle le reset ******/
/******* nouvelle partie **********/
/**********************************/

void gameOver(void){
  noTone(speaker);  // Silenciar o som
  lcd.setCursor(4,1);
  lcd.print("  Game Over ");
  delay(500);
  if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750){
    nouvellePartie();  // Reinicializar para a nova peça
  }
  lcd.setCursor(4,1);
  lcd.print("            "); 
  delay(200);
  if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750){
    nouvellePartie();  // Reinicializar para a nova peça
  }
  lcd.setCursor(4,1);
  lcd.print("Press Button");
  delay(500);
  if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750){
    nouvellePartie();  // Reinicializar para a nova peça
  }
  lcd.setCursor(4,1);
  lcd.print("            ");
  delay(200);
  if(analogRead(boutonJump) >= 500 && analogRead(boutonJump) < 750){
    nouvellePartie();  // Reinicializar para a nova peça
  }
}


/*********** ACCELERATION **********/
/****** temporise le jeu pour ******/
/********* plus de facilite ********/
/** utilise la #define difficulte **/
/***********************************/

void acceleration(void){
  static unsigned int variation=0; // Pour accélérer le jeu toutes les variation*boucle 
  static unsigned int vitesse=0;   // Pour moduler la vitesse du jeu  
  if(variation==10){       // Pour ne pas que cela s'exécute pas à chaque fois
    if(vitesse<facilite){ // facilité est une constante définie au début du programme
      vitesse=vitesse+1;
    }
    variation=0;
  }
  delay((facilite-vitesse)+1); // plus un pour ne jamais que ce soit égal à 0
  variation=variation+1;
}


// pour amélioration ultérieure afin d'éviter les tempos logicielles
/*********** mesureIntervalleDeTemps **********/
/************* Fonction qui mesure ************/
/******** l’intervalle de temps écoulé ********/
/******* entre deux appels consécutifs ********/
/**********************************************/

long mesureIntervalleDeTemps(){
  // Déclaration d’une variable locale statique nommée lastMillis réservée en RAM
  static long lastMillis=0; 
  // Déclaration d’une variable locale nommée now en pile LIFO
  long now = millis();
   // Déclaration d’une variable locale nommée intervalle en pile LIFO
  long intervalle= now-lastMillis;
  // La valeur de lastMillis perdurera entre chaque appel de cette fonction
  lastMillis = now;
  // La fonction retourne le résultat de l’intervalle de temps écoulé
  return intervalle;
}
