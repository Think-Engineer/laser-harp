#include "audio.h"
#include "mario.h"
#include "laser.h"

#define DEFAULT_VOICE   102
#define DEFAULT_VOLUME  120

/**
 *  Sets up serial output and plays a chime.
 */
void setup() {
    /* Initialise Serial */
    Serial.begin(9600);
    Serial.println("Hello EMFCamp 2018!");
    /* Initialise libraries */
    audioInit();
    laserInit();
    /* Initialise harp */
    updateVoice(DEFAULT_VOICE);
    updateVolume(DEFAULT_VOLUME);
}

/**
 *  Polls buttons and lasers and updates states accordingly.
 */
void loop() {
    laserUpdate();
    //playMario();
}
