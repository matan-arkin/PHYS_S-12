// Based on neopixel template code

#define MIC_PIN          A0

const unsigned int SAMPLEWINDOW = 25;   // sample for 25ms
const unsigned int NUMWINDOWS = 4;     // repeat 4 times and average

void setup() {
  Serial.begin(9600);
  analogReadResolution(10);
}

void loop() {
  int total = 0;
  for (int i = 0; i < NUMWINDOWS; i++)
  {
    // init
    unsigned long startMillis = millis(); // Start of sample window
    int peakToPeak = 0;   // peak-to-peak level
    int signalMax = 0;
    int signalMin = 1024;

    // collect sample window
    while (millis() - startMillis < SAMPLEWINDOW)
    {
      int sample = analogRead(A0);   //reading DC pin from pin A0
      if (sample < 1024)  // toss out spurious readings
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
  Serial.println(total / NUMWINDOWS);
}
