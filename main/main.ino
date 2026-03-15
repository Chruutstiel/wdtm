#include <BLEMIDI_Transport.h>
//#include <hardware/BLEMIDI_ESP32_NimBLE.h>
#include <hardware/BLEMIDI_ESP32.h>

BLEMIDI_CREATE_DEFAULT_INSTANCE();

// A-Minor: A B C D E F G A
const int loopedNotesMidi[] = {57, 59, 60, 62, 64, 62, 60, 59};
const String loopedNotesHuman[] = {"A", "B", "C", "D", "E", "D", "C", "B"}; 
const int loopLength = 8;

void setup() {
  Serial.begin(115200);
  Serial.println("Hallo Welt, i bims.");
  MIDI.begin();
  Serial.println("Waiting for Midi");
}

void loop() {
  MIDI.read();

  if (/* connected */ true) {
    for (int i = 0; i < loopLength; i++) {
      MIDI.sendNoteOn(loopedNotesMidi[i], 127, 1);
      Serial.println(loopedNotesHuman[i]);
      delay(400);
      MIDI.sendNoteOff(loopedNotesMidi[i], 0, 1);
      delay(100);
    }
    //delay(00); // pause before repetition 
  }

}