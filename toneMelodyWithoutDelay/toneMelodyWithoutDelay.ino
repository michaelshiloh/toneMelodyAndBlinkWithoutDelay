/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

unsigned long previousMillis = 0;
int thisNote = 0;
int pauseBetweenNotes;

void loop() {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= pauseBetweenNotes) {
    previousMillis = currentMillis;

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);

    pauseBetweenNotes = noteDuration * 1.30;

    thisNote++;
    if ( thisNote > + 8 ) {
      thisNote = 0;
    }
  }
}

void setup() {
  // no need to repeat the melody.
}
