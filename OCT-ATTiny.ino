#include <Adafruit_NeoPixel.h>

//variables for the neopixels
const int npCount = 2;
const int npPin = 1;

//variables for the photoresistor
int lightPin = A1;
int lightVal;


int redVal1 = 0;
int blueVal1 = 0;

//variable for the switch state
int switchVal = 0;

Adafruit_NeoPixel strip(npCount, npPin, NEO_GRB + NEO_KHZ800);

void setup() {
  //initalizes the neopixel strip
  strip.begin();
  //sets the brightness for the neopixel strip
  strip.setBrightness(100);
}

void loop() {
  //variable that reads the input of the photoresistor
  lightVal = analogRead(lightPin);

  // variables that change from one unit to another
  redVal1 = map(lightVal, 500, 850, 0, 255);
  blueVal1 = map(lightVal, 850, 500, 0, 255);

  switch (switchVal) {

    case 0: //case that changes pixel color based on light input
      strip.setPixelColor(0, redVal1, 0, blueVal1);
      strip.setPixelColor(1, redVal1, 0, blueVal1);
      strip.show();
  }
}
