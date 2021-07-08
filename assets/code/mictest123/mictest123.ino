//const int ledPin = 13;
//const int buttonPin = 12;
//const int micPin = A10;
//int lastMicSample = 0;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(ledPin, OUTPUT);
//  pinMode(buttonPin, INPUT_PULLUP);
//  pinMode(micPin, INPUT);
//  digitalWrite(ledPin, HIGH);
//  analogReadResolution(10);
//}
//
//void loop() {
//  int aud_amp_raw = analogRead(micPin);
//  int aud_amp = map(aud_amp_raw, 171, 232, -100, 100);
//  Serial.println(aud_amp);
//  if (abs(aud_amp - lastMicSample) > 38) {
//    if (digitalRead(ledPin) == HIGH) {
//      digitalWrite(ledPin, LOW);
//    }
//    else {
//      digitalWrite(ledPin, HIGH);
//    }
//  }
//  lastMicSample = aud_amp;
//  
//    
////  if (digitalRead(buttonPin) == HIGH) {
////    digitalWrite(ledPin, LOW);
////  }
////  else {
////    aud_amp = analogRead(micPin);
////    Serial.println(map(aud_amp, 171, 232, -100, 100));
////    digitalWrite(ledPin, HIGH);
////  }
//}

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() 
{
   Serial.begin(9600);
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A10);   //reading DC pin from pin A0
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

   Serial.println(peakToPeak);
}
