#import <Arduino.h>
#include <SoftwareSerial.h>

/* Reset is active low */
#define VS_RESET  51
/* Mode selection (0 = file / 1 = real time MIDI) */
#define VS_GPIO1  53

void audioInit();
void audioLoop();

void noteOn         (byte channel, byte note, byte attack_velocity);
void noteOff        (byte channel, byte note, byte release_velocity);

void updateVolume   (int volume);
void updateBank     (int bank);
void updateVoice    (int voice);
