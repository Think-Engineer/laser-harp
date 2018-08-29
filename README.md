# Laser Harp!
If you're reading this, you must've seen or heard about Think Engineer's Laser Harp! It's our installation for Electromagnetic Field 2018 and this repository holds the firmware for it.

## How it Works
### Hardware
The entire harp runs on a Arduino Mega 2560 Rev3 with a SparkFun MP3 Player Shield. The Arduino is fitted with a Grove shield and connects to sensors using Grove cables. The entire base is constructed using oriented strand board and painted using black fence paint.
#### Sensors
Lasers are detected by photo sensors. There are a total of 26 photo sensors on pins A0-A13 and D2-D13. Pins are HIGH when the sensor doesn't detect light (i.e. laser is broken), and LOW when the sensor detects light (i.e. laser is intact).

### Software
#### lasers.ino
This is the main entrypoint to the sketch. It initialises all of the libraries and spins a super loop to constantly poll the buttons and lasers.
#### button.h, button.cpp
Handles buttons, i.e. keeps track of and changes voices on button press.
#### laser.h, laser.cpp
Keeps track of and handles changes in laser states (if gets broken, start synthesizer).
#### audio.h, audio.cpp
Interfaces with the synthesizer to play notes.
#### mario.h, mario.cpp
Literally just plays the Super Mario theme.

## How to Contribute
* Make the firmware better/more stable - it currently jitters when the lasers are misaligned.
* Create a sketch to guide users in playing music, e.g. using a NeoPixels board.
* Update the inputs to work using interrupts, probably very difficult.
* Make it play something other than Mario.
