#include <Adafruit_NeoPixel.h>

#define LEDSTRP     6
#define MICPINR     A0
#define MICPINL     A5
const int NUMPIXELS = 10;     // 10 LEDs on LED strip
const int SAMPLEWINDOW = 100; // Sample window width in mS
const int PEAK_THRESH = 30;   // loud enough to be a clap

Adafruit_NeoPixel strip(NUMPIXELS, LEDSTRP, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(250000);
  strip.begin();            // INITIALIZE NeoPixel strip object
  strip.setBrightness(100); // (max = 255)
  strip.clear();            // Set all pixel colors to 'off'
  strip.show();             // Turn OFF all pixels ASAP
}

void loop() {
  int signal_max_left = 0;
  int signal_min_left = 1024;
  int signal_max_right = 0;
  int signal_min_right = 1024;
  unsigned long start_millis = millis(); // Start of sample window

  // sample p2p left and right for 1 SAMPLEWINDOW
  while (millis() - start_millis < SAMPLEWINDOW) {
    int sample_left = analogRead(MICPINL);
    int sample_right = analogRead(MICPINR);
    if (sample_left < 1024 && sample_right < 1024) { // toss out spurious readings
      if (sample_left > signal_max_left)
        signal_max_left = sample_left;
      else if (sample_left < signal_min_left)
        signal_min_left = sample_left;
      if (sample_right > signal_max_right)
        signal_max_right = sample_right;
      else if (sample_right < signal_min_right)
        signal_min_right = sample_right;
    }
  }
  // max - min = peak-peak amplitude
  int p2p_left = signal_max_left - signal_min_left;
  int p2p_right = signal_max_right - signal_min_right;

  // if loud enough, change side
  if (p2p_left > PEAK_THRESH || p2p_right > PEAK_THRESH) {
    strip.clear();
    // change to the louder side 
    if (p2p_left + 2 > p2p_right)
      strip.fill(strip.Color(150, 0, 0), 0, 5);
    else
      strip.fill(strip.Color(150, 0, 0), 5, 5);
    strip.show();
    delay(500);
  }
}
