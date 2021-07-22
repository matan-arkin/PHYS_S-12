#include <ESP32Servo.h>

Servo servo;

void setup() {
  servo.attach(13);
  servo.write(40);
}

void press() {
  // scan from 40 to 8 degrees, ie press down
  for(int angle = 40; angle > 8; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  }
  
  // hold for 0.8s
  delay(1400);
  
  // scan from 8 back to 40 degrees, ie let the button go
  for(int angle = 8; angle < 40; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  }
}

// assumes AC starts off
void loop() {
  // on
  press();
  // leave on 5 minutes
  delay(300000);
  // turn off
  press();
  // leave off 2 minutes
  delay(120000);
}
