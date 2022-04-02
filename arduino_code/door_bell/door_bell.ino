#include "pitches.h"  //add note library
//notes in the melody
int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

int buttonPin = 14;

//note durations. 4=quarter note / 8=eighth note
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {

  pinMode(buttonPin, INPUT);   //make the button's pin input
}

void loop() {

  int buttonState = digitalRead(buttonPin);   //read the input pin
  //if the button is pressed
  if (buttonState == 1) {
    //iterate over the notes of the melody
    for (int i = 0; i < 8; i++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations [i];
      tone(15, melody [i], noteDuration);
      //to distinguish the notes, set a minimum time between them
      //the note's duration +30% seems to work well
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
  }
  else
  {
    noTone(15);    //if the button is released, stop the tone playing.
  }
}
