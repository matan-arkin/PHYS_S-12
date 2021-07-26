#include <AccelStepper.h>

const int stepPin = 13;
const int dirPin = 12;
int next_loc = 0;

// Define a stepper and the pins it will use
AccelStepper stepper(1, stepPin, dirPin); // initialise accelstepper for a two wire board

void setup()
{
  stepper.setMaxSpeed(500);
  stepper.setSpeed(500);
}

void loop()
{
  stepper.runSpeed();
}
