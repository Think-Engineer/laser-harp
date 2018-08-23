#import <Arduino.h>
#include <SoftwareSerial.h>

void audioInit();
void audioLoop();

void noteOn (byte channel, byte note, byte attack_velocity);
void noteOff(byte channel, byte note, byte release_velocity);