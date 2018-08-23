#include <Arduino.h>
#include "laser.h"
#include "audio.h"

/* Store Button Pins */
int buttons[BUTTON_COUNT] = { 
    A0,     A1 
};

/* Store Laser Pins */
int lasers[LASER_COUNT] = {
    /* Analog pins */
    A2,     A3,
    A4,     A5,
    A6,     A7,
    A8,     A9,
    A10,    A11,
    A12,    A13,
    A14,    A15,

    /* Digital pins */
    12,     13,
    10,     11,
    9,      8,
    6,      7,
    4,      5,
    //2,      3
};

/* Store Laser States */
int laserStates[LASER_COUNT];



void laserBreak(int laser) {
    //Serial.println(String(laser) + " broken!");
    noteOn(0, 76, 127);
}

void laserIntact(int laser) {
    //Serial.println(String(laser) + " intact!");
    noteOff(0, 76, 127);
}

/**
 * Initially read and save laser states.
 */
void laserInit() {
	for (int i = 0; i < LASER_COUNT; i++) {
        if (i == 23) {
            pinMode(lasers[i], INPUT);
        } else {
            pinMode(lasers[i], INPUT_PULLUP);
        }
        laserStates[i] = digitalRead(lasers[i]);
    }
}

/**
 *  Check if lasers updated and take action.
 */
void laserUpdate() {
    //Serial.print("Checking lasers... ");
    int newState, oldState;
	for (int i = 0; i < LASER_COUNT; i++) {
        newState = digitalRead(lasers[i]);
        oldState = laserStates[i];
        //Serial.print(String(i) + "-" + String(oldState) + ">" + String(newState) + " ");
        if (newState == LASER_INTACT && oldState == LASER_BROKEN) {
            laserIntact(i);
        }
        if (newState == LASER_BROKEN && oldState == LASER_INTACT) {
            laserBreak(i);
        }
        laserStates[i] = newState;
    }
}