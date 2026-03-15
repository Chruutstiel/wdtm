# ESP32 BLE MIDI Controller

This repository contains Arduino sketches for an ESP32-based MIDI controller that sends notes and control messages to a PC via Bluetooth Low Energy (BLE).

## Requirements

### Hardware
- ESP32 Dev Module (e.g. AZDelivery LOLIN32 Lite Board V1.0)
- USB cable for programming

### Software (Arduino IDE)
- Arduino IDE 2.x
- **ESP32 Board Package** by Espressif, version **2.0.17**
  - Board Manager URL: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
- **BLEMIDI Transport** by Lathoub (available via Library Manager)

### Software (PC)
- [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html) – virtual MIDI port
- [MIDIberry](https://apps.microsoft.com/detail/9n39720h2m05) – BLE MIDI bridge for Windows
- Any DAW (e.g. LMMS, Ableton, FL Studio)

## Board Settings (Arduino IDE)

| Setting | Value |
|---|---|
| Board | ESP32 Dev Module |
| Upload Speed | 115200 |
| Flash Mode | DIO |
| Flash Frequency | 80 MHz |
| Core Debug Level | None |
| Erase All Flash | Disabled |

## Signal Chain

```
ESP32 (BLE) → MIDIberry → loopMIDI → DAW
```

### `main/`
Plays an A minor scale in an endless loop once a BLE connection is established.

### `hello_world/`
Sends single test notes (C4) to verify the BLE connection.

## Setup

1. Start loopMIDI and create a new port (e.g. `ESP32MIDI`)
2. Start MIDIberry, select the ESP32 as input and the loopMIDI port as output
3. In your DAW's MIDI settings, enable **WinMM MIDI** and select the loopMIDI port as input
4. Restart the DAW so the port is recognized
5. In the desired instrument, enable MIDI input (channel 0 = all channels)

## Notes

- Do **not** upload libraries to this repository – install them via the Arduino Library Manager instead
- After flashing, press the **EN/Reset button** on the ESP32 to properly initialize the Serial Monitor
- BLE MIDI typically has a latency of around 10–15 ms
