#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN       0
#define NUMPIXELS 7

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

const int buttonPin[] = {6, 7, 8, 9, 10, 11, 12};
const int buzzerPin = 15;
const int pitch[] = {523, 587, 659, 698, 784, 880, 988};

void setup() {

  for (int i = 0; i <  NUMPIXELS ; i++) {
    pinMode(buttonPin[i], OUTPUT);
  }
  pixels.begin();
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  //  pixels.setBrightness(50);
}

void loop() {
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    if (digitalRead(buttonPin[i]) == HIGH) {
      tone(buzzerPin, pitch[i]);
      pixels.setBrightness(100);
      pixels.setPixelColor(i, 0xFF8822);
      pixels.show();
      while (digitalRead(buttonPin[i]) == HIGH);
      fade();
      noTone(buzzerPin);
    }
  }
}

void fade() {
  while (1) {
    int brightness = pixels.getBrightness();
    if (brightness <= 0) {
      return;
    }
    pixels.setBrightness(brightness -= 1);
    pixels.show();
    delay(2);
  }
}
