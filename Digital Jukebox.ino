/*********************
 *  Corey Biluk      *
 *  December 8, 2020 *
 *********************/

/*****************************************************************************
 * This program is a juke box that plays one of five melodies based on user  *
 * input.  Tempos can be adjusted by changing the tempoMelody variables that *
 * correspond to each melody.  Higher the value, slower the tempo and vice   *
 * versa. Melodys and note lengths are broken into 2 bars of music per line. *          
 *****************************************************************************/

/*************
 * Libraries *
 *************/
#include "pitches.h"                                                                       

/*************
 * Variables *
 *************/
int outPin = 8;
int songSelect;

/********************************************
 * Star Wars Imperial March - John Williams * 
 ********************************************/
int melody1[] = 
{
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_C4, NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3,
  NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, 0, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4,
  NOTE_C4, 0, NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_GS3, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_E4,
  NOTE_A4, NOTE_A3, NOTE_A3, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, 0, NOTE_AS3, NOTE_DS4, NOTE_D4, NOTE_CS4,
  NOTE_C4, 0, NOTE_F3, NOTE_GS3, NOTE_F3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_C4, NOTE_A3, 
};
int noteLength1[] = 
{
  4, 4, 4, 5, 16, 4, 5, 16, 2,
  4, 4, 4, 5, 16, 4, 5, 16, 2,
  4, 5, 16, 4, 5, 16, 4, 8, 8, 4, 5, 16,
  4, 8, 8, 4, 5, 16, 4, 5, 16, 2,
  4, 5, 16, 4, 5, 16, 4, 8, 8, 4, 5, 16,
  4, 8, 8, 4, 5, 16, 4, 5, 16, 2
};
int tempoMelody1 = 2000;
/**********************************
 * Yellow Submarine - The Beatles * 
 **********************************/
int melody2[] = 
{
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3,
  NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, 
};
int noteLength2[] = 
{
  4, 4, 4, 5, 16, 5, 16, 5, 16, 2,
  5, 16, 5, 16, 2, 5, 16, 5, 16, 2,
  4, 4, 4, 5, 16, 5, 16, 5, 16, 2,
  5, 16, 5, 16, 2, 5, 16, 5, 16, 2,
};
int tempoMelody2 = 1500;
/*************************************
 * Ode To Joy - Ludwig Van Beethoven * 
 *************************************/
int melody3[] = 
{
  NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_D3, NOTE_D3,
  NOTE_E3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_C3,
};
int noteLength3[] = 
{
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 3, 8, 2,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 3, 8, 2,
};
int tempoMelody3 = 1000;
/************************************************************
 * Dance of the Sugar Plum Fairy - Peter Ilyich Tchaikovsky * 
 ************************************************************/
int melody4[] = 
{
  0, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_FS4, NOTE_DS4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_B3, 0,
  0, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_FS3, NOTE_C4, NOTE_B3, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_DS4, NOTE_FS4, NOTE_E4, NOTE_FS4, NOTE_DS4,  
};
int noteLength4[] = 
{
  4, 8, 8, 4, 4, 4, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 4, 4,
  4, 8, 8, 4, 4, 4, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 4,    
};
int tempoMelody4 = 1500;
/***********************************
 * "The Lick" - Internet Jazz Meme * 
 ***********************************/
int melody5[] = 
{
  NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_E3, NOTE_C3, NOTE_D3
};
int noteLength5[] = 
{
  8, 8, 8, 8, 4, 8, 1
};
int tempoMelody5 = 1000; 


void setup() {
  Serial.begin(9600);                                                               //Enable serial monitor
  pinMode(outPin, OUTPUT);                                                          //Set output pin
  Serial.println("Welcome To The JukeBot5000");                                     //Print message to console window
  Serial.println(" ");                                                              //Print empty line for formatting
}

void loop() {
  Serial.println("Please Select Song:");                                            //Prompt user to chose a song
  Serial.println(" ");                                                              //Print empty line for formatting 
  Serial.println("1 - Star Wars Imperial March - John Williams");                   //Print song choice #1
  Serial.println("2 - Yellow Submarine - The Beatles");                             //Print song choice #2
  Serial.println("3 - Ode To Joy - Ludwig Van Beethoven");                          //Print song choice #3
  Serial.println("4 - Dance Of The Sugar Plum Fairy - Peter Ilyich Tchaikovsky");   //Print song choice #4
  Serial.println("5 - 'The Lick' - Internet Jazz Meme");                            //Print song choice #5
  Serial.println(" ");                                                              //Print empty line for formatting
  while (Serial.available()==0)                                                     //Wait for user input
  {                                                                               
  }
  songSelect = Serial.parseInt();                                                   //Parse user input and set songSelect to that value
  
  if (songSelect == 1)                                                              //If user inputs 1
  {
    for (int Note1 = 0; Note1 < 62; Note1++)                                        //Loop to play the melody. 62 is the number of notes in the melody
    {
     int noteDuration1 = tempoMelody1 / noteLength1[Note1];                         //Tempo is divided by the notelength
      tone(outPin, melody1[Note1], noteDuration1);                                  //Output the pitch for time equal to noteDuration
      int notePause1 = noteDuration1 * 1.30;                                        //Determines a delay length to place space between notes
      delay(notePause1);                                                            //Delay for space between notes
      noTone(outPin);                                                               //Stop output 
    }
  }  
  if (songSelect == 2)                                                              //If user inputs 2
  {
    for (int Note2 = 0; Note2 < 40; Note2++)                                        //Loop to play the melody. 40 is the number of notes in the melody
    {
     int noteDuration2 = tempoMelody2 / noteLength2[Note2];                         //Tempo is divided by the notelength
      tone(outPin, melody2[Note2], noteDuration2);                                  //Output the pitch for time equal to noteDuration
      int notePause2 = noteDuration2 * 1.30;                                        //Determines a delay length to place space between notes
      delay(notePause2);                                                            //Delay for space between notes
      noTone(outPin);                                                               //Stop output
    }
  }
  if (songSelect == 3)                                                              //If user inputs 3
  {
    for (int Note3 = 0; Note3 < 32; Note3++)                                        //Loop to play the melody. 32 is the number of notes in the melody
    {
     int noteDuration3 = tempoMelody3 / noteLength3[Note3];                         //Tempo is divided by the notelength
      tone(outPin, melody3[Note3], noteDuration3);                                  //Output the pitch for time equal to noteDuration
      int notePause3 = noteDuration3 * 1.30;                                        //Determines a delay length to place space between notes
      delay(notePause3);                                                            //Delay for space between notes
      noTone(outPin);                                                               //Stop output
    }
  }
    if (songSelect == 4)                                                            //If user inputs 4
  {
    for (int Note4 = 0; Note4 < 43; Note4++)                                        //Loop to play the melody. 43 is the number of notes in the melody
    {
     int noteDuration4 = tempoMelody4 / noteLength4[Note4];                         //Tempo is divided by the notelength
      tone(outPin, melody4[Note4], noteDuration4);                                  //Output the pitch for time equal to noteDuration
      int notePause4 = noteDuration4 * 1.30;                                        //Determines a delay length to place space between notes
      delay(notePause4);                                                            //Delay for space between notes
      noTone(outPin);                                                               //Stop output
    }
  }
  if (songSelect == 5)                                                              //If user inputs 5
  {
    for (int Note5 = 0; Note5 < 7; Note5++)                                         //Loop to play the melody. 7 is the number of notes in the melody
    {
     int noteDuration5 = tempoMelody5 / noteLength5[Note5];                         //Tempo is divided by the notelength
      tone(outPin, melody5[Note5], noteDuration5);                                  //Output the pitch for time equal to noteDuration       
      int notePause5 = noteDuration5 * 1.30;                                        //Determines a delay length to place space between notes
      delay(notePause5);                                                            //Delay for space between notes
      noTone(outPin);                                                               //Stop output
    }
  }
  if (songSelect < 1 || songSelect > 5)                                             //Input Error Check - determines if input is between 1 and 5
  { 
    Serial.println("Not A Valid Input");                                            //Print input error message
    Serial.println("JukeBot5000 Rebooting...");
  }
  Serial.println(" ");                                                              //Print message to console window.
  Serial.println("Thank You For Using JukeBot5000");
  Serial.println("===============================");
  delay(1000);
  Serial.println(" ");                                                              //This is a countdown till the user can choose another song
  Serial.println("Choose Another Song In...");                                      //This isnt necessary for the program, I just put it in for fun.  
  delay(1000);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("...");
  delay(500);
  Serial.println(" ");
  Serial.print(" ");
}
