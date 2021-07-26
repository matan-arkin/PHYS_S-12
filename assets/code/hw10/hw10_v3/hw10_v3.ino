// based on template from https://nathanmelenbrink.github.io/intro-dig-fab/09_networking/huzzah1b.html
// NEED TO INSERT PASSWORD AND SSID FOR THIS TO ACTUALLY RUN

#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library
#include <AccelStepper.h>

#define FIREBASE_HOST "https://acontroller-aadb8-default-rtdb.europe-west1.firebasedatabase.app/"  // the project name address from firebase id
#define FIREBASE_AUTH "cAdMvfIBB8BVwihI1A19RnIe37LriNSuFVNClYgs"                          // the secret key generated from firebase
#define WIFI_SSID "Arkin-Fox"                                   // input your home or public wifi name
#define WIFI_PASSWORD "086a0a2170b4"                           // password of wifi ssid

const int stepPin = 13;
const int dirPin = 12;
const unsigned long TEADELAY = 8700;
int next_loc = 0;
String fireString = "";                                          // led status received from firebase

//Define FirebaseESP32 data object
FirebaseData firebaseData;

// Define a stepper and the pins it will use
AccelStepper stepper(1, stepPin, dirPin); // initialise accelstepper for a two wire board

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                          // try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                // print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
  Firebase.reconnectWiFi(true);
  Firebase.set(firebaseData, "/NEED_TEA", "NO");              // set initial string of "OFF"

  // prep motor speed
  stepper.setMaxSpeed(500);
  stepper.setSpeed(500);
}

void loop() {
  Firebase.get(firebaseData, "/NEED_TEA");                     // get led status input from firebase
  fireString = firebaseData.stringData();                        // change to e.g. intData() or boolData()
  Serial.print("Got NEED_TEA=");
  Serial.println(fireString);
  
  if (fireString == "YES") {                    // compare the input of led status received from firebase
    Serial.println("Getting your tea...");
    unsigned long start_time = millis();
    while (millis() - start_time < TEADELAY) {
      stepper.runSpeed();      
    }
//    stepper.stop();
    Firebase.set(firebaseData, "/NEED_TEA", "NO");
  }

  else if (fireString == "NO") {              // compare the input of led status received from firebase
    Serial.println("No need for tea. Keep waiting.");
  }

  else {
    Serial.println("Please send YES/NO");
  }

  delay(1000);                                 // not strictly necessary
}
