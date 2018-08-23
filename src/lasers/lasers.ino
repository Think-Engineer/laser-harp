#include "audio.h"
#include "mario.h"

#define BUTTON_COUNT    2
#define LASER_COUNT     26

#define LASER_BROKEN    HIGH
#define LASER_INTACT    LOW

/* Button pins */
int buttons[BUTTON_COUNT] = { 
    A0,     A1 
};

/* Laser pins */
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
    2,      3
};

/**
 *  Sets up serial output and plays a chime.
 */
void setup() {
    Serial.begin(9600);
    Serial.println("Hello EMF!");
    audioInit();
}

/**
 *  Polls buttons and lasers and updates states accordingly.
 */
void loop() {
    /* Check buttons */
    Serial.print("Checking buttons... ");
	for (int i = 0; i < BUTTON_COUNT; i++) {
        Serial.print(i);
        Serial.print(" ");
    }
    Serial.println();

    /* Poll lasers */
    /* HIGH - broken, LOW - intact */
    Serial.print("Checking lasers... ");
    int read;
	for (int i = 0; i < LASER_COUNT; i++) {
        read = digitalRead(lasers[i]);
        Serial.print(i);
        Serial.print("-");
        Serial.print(read);
        if (read == LASER_INTACT) {
            Serial.print("i");
        } else if (read == LASER_BROKEN) {
            Serial.print("b");
        }
        Serial.print(" ");
    }
    Serial.println();
    playMario();
}
