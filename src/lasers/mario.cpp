#include "mario.h"

/* Tracks notes and lengths in seperate parts */
int tunes[7][128] = {
    { 76, 12, 76, 12, 20, 12, 76, 12, 20, 12, 72, 12, 76, 12, 20, 12, 79, 12, 20, 36, 67, 12, 20, 36 },
    { 72, 12, 20, 24, 67, 12, 20, 24, 64, 12, 20, 24, 69, 12, 20, 12, 71, 12, 20, 12, 70, 12, 69, 12, 20, 12, 67, 16, 76, 16, 79, 16, 81, 12, 20, 12, 77, 12, 79, 12, 20, 12, 76, 12, 20, 12, 72, 12, 74, 12, 71, 12, 20, 24 },
    { 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 60, 12, 76, 12, 53, 12, 68, 12, 69, 12, 72, 12, 60, 12, 69, 12, 72, 12, 74, 12, 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 55, 12, 76, 12, 20, 12, 84, 12, 20, 12, 84, 12, 84, 12 },
    { 55, 12, 20, 12, 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 60, 12, 76, 12, 53, 12, 68, 12, 69, 12, 72, 12, 60, 12, 69, 12, 72, 12, 74, 12, 48, 12, 20, 12, 75, 24, 20, 12, 74, 24, 20, 12, 72, 24, 20, 12, 55, 12, 55, 12, 20, 12, 48, 12 },
    { 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 20, 12, 76, 12, 72, 12, 20, 12, 69, 12, 67, 12, 20, 12, 43, 12, 20, 12, 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 76, 12, 55, 12, 20, 24, 48, 12, 20, 24, 43, 12, 20, 12, 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 20, 12, 76, 12, 72, 12, 20, 12, 69, 12, 67, 12, 20, 12, 43, 12, 20, 12, 76, 12, 76, 12, 20, 12, 76, 12, 20, 12, 72, 12, 76, 12, 20, 12, 79, 12, 20, 36, 67, 12, 20, 36 },
    { 76, 12, 72, 12, 20, 12, 67, 12, 55, 12, 20, 12, 68, 12, 20, 12, 69, 12, 77, 12, 53, 12, 77, 12, 69, 12, 60, 12, 53, 12, 20, 12, 71, 16, 81, 16, 81, 16, 81, 16, 79, 16, 77, 16, 76, 12, 72, 12, 55, 12, 69, 12, 67, 12, 60, 12, 55, 12, 20, 12, 76, 12, 72, 12, 20, 12, 67, 12, 55, 12, 20, 12, 68, 12, 20, 12, 69, 12, 77, 12, 53, 12, 77, 12, 69, 12, 60, 12, 53, 12, 20, 12, 71, 12, 77, 12, 20, 12, 77, 12, 77, 16, 76, 16, 74, 16, 72, 12, 64, 12, 55, 12, 64, 12, 60, 12, 20, 36 },
    { 72, 12, 20, 24, 67, 12, 20, 24, 64, 24, 69, 16, 71, 16, 69, 16, 68, 24, 70, 24, 68, 24, 67, 12, 65, 12, 67, 48 }
};

/* Tracks order of parts to play */
int order[15] = {
    0, 1, 1, 2, 3, 2, 3, 4, 1, 1, 5, 5, 4, 5, 6
};

/* Plays given part */
void playPart(int part) {
    Serial.print("Part ");
    Serial.println(part);
    int length = sizeof(tunes[part]);
    for (int i = 0; i < length / 2; i++) {
        noteOn(0, tunes[part][i * 2], 127);
        delay(tunes[part][i * 2 + 1] * LENGTH);
        noteOff(0, tunes[part][i * 2], 127);
    }
}

/* Plays entire song */
void playMario() {
    for (int i = 0; i < sizeof(order); i++) {
        playPart(order[i]);
    }
}
