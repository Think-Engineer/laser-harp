#include "audio.h"

SoftwareSerial midiSerial(2, 3); // Soft TX on 3, RX not used (2 is an input anyway, for VS_DREQ)

/* Private functions */

/**
 *	Write raw data to MIDI serial.
 */
void sendMIDI(byte data) {
	midiSerial.write(data);
}

/** 
 *	Plays a MIDI note. 
 *	Doesn't check to see that cmd is greater than 127, or that data values are less than 127 
 */
void talkMIDI(byte cmd, byte data1, byte data2) {
	/* Execute command */
	sendMIDI(cmd);
	/* Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes */
	if ((cmd & 0xF0) <= 0xB0 || (cmd & 0xF0) >= 0xE0) {
		sendMIDI(data1);
		sendMIDI(data2);
	} else {
		sendMIDI(data1);
	}
}



/* Public functions */

/**
 *	Initialises the Audio Chip.
 */
void audioInit() {
	midiSerial.begin(31250);
	pinMode(VS_RESET, OUTPUT);
	Serial.println("\n******\n");
	Serial.println("MP3 Shield Example");

	/* Initialize VS1053 chip */
	digitalWrite(VS_RESET, LOW); 	// Put VS1053 into hardware reset
	delayMicroseconds(1);
	digitalWrite(VS_RESET, HIGH);	// Bring up VS1053
	pinMode(VS_GPIO1, OUTPUT);
	digitalWrite(VS_GPIO1, HIGH);	// Enable real time MIDI mode

	/* Setup chip */
  	talkMIDI(0xB0, 0x07, 120);		// 0xB0 is channel message, set channel volume to near max (127)
    talkMIDI(0xB0, 0, 0x00); 		// Default bank GM1
    talkMIDI(0xC0, 46, 0); 			// Set instrument number. 0xC0 is a 1 data byte command
}

/** 
 *	Send a MIDI note-on message. Like pressing a piano key.
 *	channel ranges from 0-15
 */
void noteOn(byte channel, byte note, byte attack_velocity) {
  	talkMIDI((0x90 | channel), note, attack_velocity);
}

/**
 *	Send a MIDI note-off message. Like releasing a piano key.
 */
void noteOff(byte channel, byte note, byte release_velocity) {
  	talkMIDI((0x80 | channel), note, release_velocity);
}