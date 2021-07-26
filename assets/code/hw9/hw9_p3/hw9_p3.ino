// based on template from https://nathanmelenbrink.github.io/intro-dig-fab/09_networking/huzzah1b.html

#include <WiFi.h>                                 // esp32 library
#include <FirebaseESP32.h>                        // firebase library
#include <ESP32Servo.h>

#define FIREBASE_HOST "https://acontroller-aadb8-default-rtdb.europe-west1.firebasedatabase.app/"  // the project name address from firebase id
#define FIREBASE_AUTH "cAdMvfIBB8BVwihI1A19RnIe37LriNSuFVNClYgs"                          // the secret key generated from firebase
#define WIFI_SSID "myssid"                                // input your home or public wifi name
#define WIFI_PASSWORD "mypass"                            // password of wifi ssid

Servo servo;
String fireString = "";                                          // AC status received from firebase
String prev_ac_status = "OFF";

//Define FirebaseESP32 data object
FirebaseData firebaseData;

void press() {
  // scan from 40 to 8 degrees, ie press down
  for(int angle = 40; angle > 8; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  }
  
  // hold for 1s
  delay(1000);
  
  // scan from 8 back to 40 degrees, ie let the button go
  for(int angle = 8; angle < 40; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  }
}

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
  Firebase.set(firebaseData, "/AC_STATUS", "OFF");              // set initial string of "OFF"
  
  servo.attach(13);
  servo.write(40);
}

void loop() {
  Firebase.get(firebaseData, "/AC_STATUS");                     // get AC status input from firebase
  fireString = firebaseData.stringData();                        // change to e.g. intData() or boolData()
  Serial.println(fireString);

  if (!(fireString == "ON" || fireString == "OFF")) {
    // invalid input
    Serial.println("Please send ON/OFF");
  }

  else {
    // valid input
    if (fireString != prev_ac_status) {                    // compare the input of AC status received from firebase
      // toggle required
      Serial.println("Toggling AC");
      press();
    }
    prev_ac_status = fireString;
  }

  delay(1000);                                 // not strictly necessary
}
