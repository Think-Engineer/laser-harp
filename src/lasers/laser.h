#pragma once
#include <Arduino.h>
#include "audio.h"

#define BUTTON_COUNT    2
//#define LASER_COUNT     26
#define LASER_COUNT     24

#define LASER_BROKEN    HIGH
#define LASER_INTACT    LOW

void laserInit();
void laserUpdate();