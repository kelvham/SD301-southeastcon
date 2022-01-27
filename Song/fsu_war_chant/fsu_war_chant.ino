#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4, 0, NOTE_F4, NOTE_E4, NOTE_C4,
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_F3, NOTE_E3, NOTE_F3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2, 4, 8, 8, 2, 8, 8, 8, 2, 4, 8, 8, 4, 8, 2
};
void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(12, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(12);
  }
}

void loop() {
  // no need to repeat the melody.
}
