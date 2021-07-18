// Based on neopixel template code

#include <Adafruit_NeoPixel.h>

#define PIN         6 
#define NUMPIXELS   10 
#define SAMPLEDELAY 400 // Time (in milliseconds) to pause between audio samples

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
unsigned long prev_sample = 0;   // Time (in milliseconds) when last sample was taken


void setup() {
  strip.begin();            // INITIALIZE NeoPixel strip object
  strip.setBrightness(10);  // Set BRIGHTNESS low to reduce draw (max = 255)
  strip.clear();            // Set all pixel colors to 'off'
  strip.show();             // Turn OFF all pixels ASAP
}

// volume is 0 (silence), or 1 to 5
unsigned int sample_volume() {
  return random(0, 6);
}

void loop() {
  unsigned long cur_sample = millis();

  if (cur_sample - prev_sample > SAMPLEDELAY) {
    prev_sample = millis();
    unsigned int volume = sample_volume();
    strip.clear();
    if (volume) {
      strip.fill(strip.Color(150, 0, 0), 5 - volume, volume * 2); // color "volume" number of center LEDs red      
    }
    strip.show();   // Send the updated pixel colors to the hardware.
  }
}
