#include "pitches.h"

// notes in the melody:
int melodyfsu[] = {
  NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4, 0, NOTE_F4, NOTE_E4, NOTE_C4,
  NOTE_B3, NOTE_C4, NOTE_B3, NOTE_F3, NOTE_E3, NOTE_F3
};
int melodyfamu[] = {
  0, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, 0, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_G4, NOTE_C4, 0
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurationsfsu[] = {
  2, 4, 8, 8, 2, 8, 8, 8, 2, 4, 8, 8, 4, 8, 2
};
int noteDurationsfamu[] = {
  1, 2, 2, 2, 1, 2, 4, 4, 4, 4, 4, 4, 1, 1
};
void setup() {
  // no need to repeat the melody.
}
void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDurationfsu = 1000 / noteDurationsfsu[thisNote];
    tone(2, melodyfsu[thisNote], noteDurationfsu);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurationfsu * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(2);
  }
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDurationfamu = 1000 / noteDurationsfamu[thisNote];
    tone(2, melodyfamu[thisNote], noteDurationfamu);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurationfamu * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(2);
  }
}
