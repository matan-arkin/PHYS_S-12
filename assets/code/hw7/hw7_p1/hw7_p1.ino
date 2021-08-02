//#include <SoftwareSerial.h>
#include <driver/adc.h>

#define MICPIN A2

const int sampleWindow = 25; // Sample window width in mS
unsigned int sample;

unsigned int total;

void setup()
{
  Serial.begin(9600);
  adcAttachPin(MICPIN);
  analogReadResolution(12);
  analogSetAttenuation(ADC_0db);
  adc1_config_width(ADC_WIDTH_12Bit);
}


void loop()
{
  total = 0;
  for (int i = 0; i < 4; i++)
  {
    unsigned long startMillis = millis(); // Start of sample window
    unsigned int peakToPeak = 0;   // peak-to-peak level

    unsigned int signalMax = 0;
    unsigned int signalMin = 4096;

    while (millis() - startMillis < sampleWindow)
    {
      sample = analogRead(MICPIN);   //reading DC pin from pin A0
      if (sample < 4096)  // toss out spurious readings
      {
        if (sample > signalMax)
        {
          signalMax = sample;  // save just the max levels
        }
        else if (sample < signalMin)
        {
          signalMin = sample;  // save just the min levels
        }
      }
    }
    peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
    total += peakToPeak;
  }
  Serial.println(total / 4);
}
