const int ledPin = 13;
const int buttonPin = 12;
const int micPin = A10;
int aud_amp = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(micPin, INPUT);
  analogReadResolution(10);
}

void loop() {
  
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  }
  else {
    aud_amp = analogRead(micPin);
    Serial.println(map(aud_amp, 171, 232, -100, 100));
    digitalWrite(ledPin, HIGH);
  }
}
