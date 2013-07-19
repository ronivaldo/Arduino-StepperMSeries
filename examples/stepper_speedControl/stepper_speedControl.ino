
/* 
 Stepper Motor Control - speed control
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor driver is attached to digital pins 8,9 of the Arduino.
 A potentiometer is connected to analog input 0.
 
 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps, 
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.
 
 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe
 
 */

#include <StepperMSeries.h>

// change this to the number of steps on your motor
#define STEPS 200
#define PULSE_PIN 8
#define DIRECTION_PIN 9

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
StepperMSeries stepper(STEPS, PULSE_PIN, DIRECTION_PIN);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    stepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    stepper.step(STEPS/100);
  } 
}


