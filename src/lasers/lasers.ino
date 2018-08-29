#include "audio.h"
#include "mario.h"
#include "laser.h"
#include "button.h"

#define DEFAULT_VOICE   46
#define DEFAULT_VOLUME  120

int useVoice = 0;

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
    buttonInit();
    /* Initialise harp */
    updateVoice(DEFAULT_VOICE);
    updateVolume(DEFAULT_VOLUME);
}

/**
 *  Polls buttons and lasers and updates states accordingly.
 */
void loop() {
    int voice = buttonUpdate();
    /* If voice changed */
    if (voice > 0) {
      useVoice = voice;
      laserInit();
    }
    laserUpdate(useVoice);
    //playMario(); //DEBUG
}
