#include <BLEMIDI_Transport.h>
//#include <hardware/BLEMIDI_ESP32_NimBLE.h>
#include <hardware/BLEMIDI_ESP32.h>

BLEMIDI_CREATE_DEFAULT_INSTANCE();


void setup() {
  Serial.begin(115200);
  Serial.println("Hallo Welt, i bims.");
  MIDI.begin();
  Serial.println("Waiting for Midi");
}

void loop() {
  MIDI.read();

  // Beispiel: Note C4 alle 1 Sekunde senden
  MIDI.sendNoteOn(60, 127, 1);   // Note, Velocity, Kanal
  delay(500);
  MIDI.sendNoteOff(60, 0, 1);
  Serial.println("Düdeldü.");
  delay(500);
}