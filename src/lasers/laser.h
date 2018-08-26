#pragma once
#include <Arduino.h>
#include "audio.h"

#define BUTTON_COUNT    2
//#define LASER_COUNT     26 //TODO: Undo after hardware Serial
//#define LASER_COUNT     24 //TODO: Undo after buttons installed
#define LASER_COUNT     26

#define LASER_BROKEN    HIGH
#define LASER_INTACT    LOW

#define FLIP_TRIGGERS 1

void laserInit();
void laserUpdate();
