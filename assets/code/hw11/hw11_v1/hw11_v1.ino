// Based on neopixel template code

#include <Adafruit_NeoPixel.h>

#define MICR_PIN          A0
#define MICL_PIN          A5

const unsigned int SAMPLEWINDOW = 100;   // Represents quantum unit to be considered by machine learning, in milliseconds
unsigned long start_time = 0;            // Time (in milliseconds) when sampling started

void setup() {
  Serial.begin(9600);
  analogReadResolution(10);
  start_time = millis();
}

void loop() {
  unsigned long window_num = (millis() - start_time) / 100;
  unsigned int sample_left = analogRead(MICL_PIN);
  unsigned int sample_right = analogRead(MICR_PIN);
  
  if (sample_left < 1024 && sample_right < 1024) {      // toss out spurious readings
    Serial.print("Left: #");
    Serial.print(window_num);
    Serial.print(": ");
    Serial.println(sample_left);
    Serial.print("Right: #");
    Serial.print(window_num);
    Serial.print(": ");
    Serial.println(sample_right);
  }
}
