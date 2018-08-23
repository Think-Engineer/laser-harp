#include "audio.h"
#include "mario.h"
#include "laser.h"

/**
 *  Sets up serial output and plays a chime.
 */
void setup() {
    Serial.begin(9600);
    Serial.println("Hello EMF!");
    audioInit();
    laserInit();
}

/**
 *  Polls buttons and lasers and updates states accordingly.
 */
void loop() {
    laserUpdate();
    //playMario();

    /* Check buttons 
    Serial.print("Checking buttons... ");
	for (int i = 0; i < BUTTON_COUNT; i++) {
        Serial.print(i);
        Serial.print(" ");
    }
    Serial.println();

     Poll lasers */
    
}
