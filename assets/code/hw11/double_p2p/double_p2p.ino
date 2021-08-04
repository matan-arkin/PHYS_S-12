#include <driver/adc.h>

#define MICR_PIN          A7
#define MICL_PIN          A9

const unsigned int SAMPLEWINDOW = 100;   // Represents quantum unit to be considered by machine learning, in milliseconds
unsigned long start_time = 0;            // Time (in milliseconds) when sampling started

const int sampleWindow = 25; // Sample window width in mS
unsigned int sample_left;
unsigned int sample_right;
unsigned int total_left;
unsigned int total_right;

void setup() {
  Serial.begin(9600);
//  analogReadResolution(10);
//  adcAttachPin(MICR_PIN);
//  adcAttachPin(MICL_PIN);
  analogReadResolution(12);
  start_time = millis();
}

void loop() {
  unsigned long window_num = (millis() - start_time) / 100;
  total_left = 0;
  total_right = 0;
  
  for (int i = 0; i < 4; i++)
  {
    unsigned long startMillis = millis(); // Start of sample window
    unsigned int p2p_left = 0;   // peak-to-peak level
    unsigned int p2p_right = 0;   // peak-to-peak level

    unsigned int signal_max_left = 0;
    unsigned int signal_max_right = 0;
    unsigned int signal_min_left = 4096;
    unsigned int signal_min_right = 4096;

    while (millis() - startMillis < sampleWindow)
    {
//      analogSetAttenuation(ADC_ATTEN_2_5db);
      adc1_config_channel_atten(ADC1_CHANNEL_5, ADC_ATTEN_0db);
      adc1_config_width(ADC_WIDTH_BIT_12);
      unsigned int sample_left = adc1_get_raw(ADC1_CHANNEL_5);
//      unsigned int sample_left = analogRead(MICL_PIN);
//      analogSetAttenuation(ADC_ATTEN_2_5db);
      adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_0db);
      adc1_config_width(ADC_WIDTH_BIT_12);
      unsigned int sample_right = adc1_get_raw(ADC1_CHANNEL_4);
//      unsigned int sample_right = analogRead(MICR_PIN);
      if (sample_left < 4096 && sample_right < 4096)  // toss out spurious readings
      {
        if (sample_left > signal_max_left)
        {
          signal_max_left = sample_left;  // save just the max levels
        }
        else if (sample_left < signal_min_left)
        {
          signal_min_left = sample_left;  // save just the min levels
        }

        if (sample_right > signal_max_right)
        {
          signal_max_right = sample_right;  // save just the max levels
        }
        else if (sample_right < signal_min_right)
        {
          signal_min_right = sample_right;  // save just the min levels
        }
      }
    }
    p2p_left = signal_max_left - signal_min_left ;  // max - min = peak-peak amplitude
    p2p_right = signal_max_right - signal_min_right ;  // max - min = peak-peak amplitude
    total_left += p2p_left;
    total_right += p2p_right;
  }
  
  Serial.print("Left: #");
  Serial.print(window_num);
  Serial.print(": ");
  Serial.println(total_left);
//  Serial.print("Right: #");
//  Serial.print(window_num);
//  Serial.print(": ");
//  Serial.println(total_right);
}
