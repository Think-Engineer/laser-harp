#import <Arduino.h>
#include <SoftwareSerial.h>

#define VS_RESET  8             // Reset is active low
#define VS_GPIO1  4             // Mode selection (0 = file / 1 = real time MIDI)

void audioInit();
void audioLoop();

void noteOn (byte channel, byte note, byte attack_velocity);
void noteOff(byte channel, byte note, byte release_velocity);