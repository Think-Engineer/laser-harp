#import <Arduino.h>
#include <SoftwareSerial.h>

/* Reset is active low */
#define VS_RESET  8
/* Mode selection (0 = file / 1 = real time MIDI) */
#define VS_GPIO1  4

void audioInit();
void audioLoop();

void noteOn         (byte channel, byte note, byte attack_velocity);
void noteOff        (byte channel, byte note, byte release_velocity);

void updateVolume   (int volume);
void updateBank     (int bank);
void updateVoice    (int voice);