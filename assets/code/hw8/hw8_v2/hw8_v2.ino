// Based on neopixel template code

#include <Adafruit_NeoPixel.h>

#define PIN         6 
#define NUMPIXELS   10 
#define SAMPLEDELAY 100 // Time (in milliseconds) to pause between audio samples

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
unsigned long prev_sample = 0;   // Time (in milliseconds) when last sample was taken
unsigned int signalMax = 0;
unsigned int signalMin = 1024;


void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  strip.begin();            // INITIALIZE NeoPixel strip object
  strip.setBrightness(10);  // Set BRIGHTNESS low to reduce draw (max = 255)
  strip.clear();            // Set all pixel colors to 'off'
  strip.show();             // Turn OFF all pixels ASAP
}

// volume is 0 (silence), or 1 to 5
unsigned int sample_volume() {
  unsigned int peak_to_peak = signalMax - signalMin;
  const unsigned int min = 20;
  const unsigned int max = 35;
  Serial.println(peak_to_peak);
  if (peak_to_peak < min) {
    return 0;
  }
  else if (peak_to_peak > max) {
    return 5;
  }
  else {
    return map(peak_to_peak, min, max, 1, 5);
  }
}

void loop() {
  unsigned long cur_sample = millis();

  if (cur_sample - prev_sample > SAMPLEDELAY) {
    // volume is 0 (silence), or 1 to 5
    unsigned int volume = sample_volume();

    strip.clear();
    if (volume) {
      strip.fill(strip.Color(150, 0, 0), 5 - volume, volume * 2); // color "volume" number of center LEDs red      
    }
    strip.show();   // Send the updated pixel colors to the hardware.

    // set up for next sample
    prev_sample = millis();
    signalMax = 0;
    signalMin = 1024;
  }

  unsigned int sample = analogRead(A0);
  if (sample < 1024) {      // toss out spurious readings
    if (sample > signalMax) {
      signalMax = sample;   // save just the max levels
    }
    else if (sample < signalMin) {
      signalMin = sample;   // save just the min levels
    }
  }
}
