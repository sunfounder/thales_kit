// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN       0
#define NUMPIXELS 8
#define SWITCH    14

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

int ledIndex = 0;

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pinMode(SWITCH, OUTPUT);
}

void loop() {
  if (ledIndex < 0) {
    ledIndex = NUMPIXELS-1;
  }
  else if (ledIndex >= NUMPIXELS) {
    ledIndex = 0;
  }
  pixels.clear(); // Set all pixel colors to 'off'
  if (digitalRead(SWITCH) == 1) {
    pixels.setPixelColor(ledIndex, pixels.Color(100, 50, 0));
    pixels.show();
    ledIndex++;
  }
  else{
    pixels.setPixelColor(ledIndex, pixels.Color(100, 50, 0));
    pixels.show();
    ledIndex--;
  }
  delay(DELAYVAL); // Pause before next pass through loop
}
