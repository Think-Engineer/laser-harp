#pragma once
#include <Arduino.h>
#include "audio.h"
#include "button.h"

#define VOICE_COUNT 10

#define BUTTON_COUNT    2
#define LASER_COUNT     26

#define LASER_BROKEN    HIGH
#define LASER_INTACT    LOW

#define NOTE_OFFSET     48

void laserInit();
void laserUpdate(int voice);
