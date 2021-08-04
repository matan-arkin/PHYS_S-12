#define MICPIN A0

const int sampleWindow = 25; // Sample window width in mS

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  unsigned int sample;
  unsigned long startMillis = millis(); // Start of sample window

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(MICPIN);   //reading DC pin from pin A0
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
  
  Serial.println(signalMax - signalMin); // max - min = peak-peak amplitude
}
