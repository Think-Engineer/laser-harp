#include "laser.h"

/* Store Laser Pins */
int lasers[LASER_COUNT] = {
    /* Analog pins */
    A0,     A1,
    A2,     A3,
    A4,     A5,
    A6,     A7,
    A8,     A9,
    A10,    A11,
    A12,    A13,

    /* Digital pins */
    12,     13,
    10,     11,
    9,      8,
    6,      7,
    4,      5,
    2,      3
};

/* Specify which voices to flip */
bool flip[VOICE_COUNT]  = {  1,   0,  1,  0,   0,  0,  0,  0,  0,  1 };

/* Store Laser States */
int laserStates[LASER_COUNT];

/**
 *  Handle laser being broken (user strumming the string).
 */
void laserBreak(int laser, int voice) {
  if(flip[voice]) {
    noteOff(0, laser + NOTE_OFFSET, 127);
  } else {
    noteOn(0, laser + NOTE_OFFSET, 127);
  }
}

/**
 *  Handle laser becoming intact (user stops strumming the string).  
 */
void laserIntact(int laser, int voice) {
  if(flip[voice]) {
    noteOn(0, laser + NOTE_OFFSET, 127);
  } else {
    noteOff(0, laser + NOTE_OFFSET, 127);
  }
}

/**
 * Read and save initial laser states.
 */
void laserInit() {
	for (int i = 0; i < LASER_COUNT; i++) {
        pinMode(lasers[i], INPUT);
        laserStates[i] = digitalRead(lasers[i]);
        noteOff(0, i + NOTE_OFFSET, 127);
    }
}

/**
 *  Check if lasers updated and take action.
 */
void laserUpdate(int voice) {
  int newState, oldState;
	for (int i = 0; i < LASER_COUNT; i++) {
        /* Fetch states */
        newState = digitalRead(lasers[i]);
        oldState = laserStates[i];
        /* Check if there is change */
        if (newState == LASER_INTACT && oldState == LASER_BROKEN) {
            laserIntact(i, voice);
        }
        if (newState == LASER_BROKEN && oldState == LASER_INTACT) {
            laserBreak(i, voice);
        }
        /* Update state */
        laserStates[i] = newState;
    }
}
