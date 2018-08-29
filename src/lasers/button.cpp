#include "button.h"

/* Store Button Pins and Values */
int nextButton = A14; //TODO: update after buttons installed
int nextButtonValue;
int prevButton = A15;
int prevButtonValue;

/* Store voices */
int voices[VOICE_COUNT] = { 46, 102, 12, 18, 101, 91, 89, 80, 95, 45 };
int currentVoice = 0;

void saveVoice() {
    updateVoice(voices[currentVoice]);
    
    /* Plays chord */
    noteOn(0, 36, 127);
    noteOn(0, 48, 127);
    noteOn(0, 52, 127);
    noteOn(0, 55, 127);
    delay(250);
    noteOff(0, 36, 127);
    noteOff(0, 48, 127);
    noteOff(0, 52, 127);
    noteOff(0, 55, 127);
}

int nextVoice() {
    currentVoice = (currentVoice + 1) % VOICE_COUNT;
    saveVoice();
    return currentVoice;
}

int prevVoice() {
    currentVoice = (currentVoice - 1);
    if (currentVoice < 0) {
        currentVoice += VOICE_COUNT;
    }
    saveVoice();
    return currentVoice;
}

void buttonInit() {
    pinMode(nextButton, INPUT_PULLUP);
    pinMode(prevButton, INPUT_PULLUP);
    nextButtonValue = digitalRead(nextButton);
    prevButtonValue = digitalRead(prevButton);
}

/**
 * Returns value if voice updated. Returns -1 if not.
 */
int buttonUpdate() {
    int newNextButtonValue = digitalRead(nextButton);
    int newPrevButtonValue = digitalRead(prevButton);

    int newVoice = -1;

    /* Next Button clicked down */
    if (newNextButtonValue == LOW && nextButtonValue == HIGH) {
        newVoice = nextVoice();       
    }
    /* Prev Button clicked down */
    if (newPrevButtonValue == LOW && prevButtonValue == HIGH) {
        newVoice = prevVoice();      
    }

    prevButtonValue = newPrevButtonValue;
    nextButtonValue = newNextButtonValue;

    return newVoice;
}
