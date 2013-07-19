
/* 
 Stepper Motor Control - one step at a time
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor driver is attached to digital pins 8,9 of the Arduino.

 The motor will step one step at a time, very slowly.  You can use this to
 test that you've got the four wires of your stepper wired to the correct
 pins. If wired correctly, all steps should be in the same direction.
 
 Use this also to count the number of steps per revolution of your motor,
 if you don't know it.  Then plug that number into the oneRevolution
 example to see if you got it right.
 
 Changed by Ronivaldo Sampaio to M Series
 2013
 https://github.com/ronivaldo/Arduino-StepperMSeries
 
 Original:
 http://www.arduino.cc/en/Reference/Stepper
 This example code is in the public domain.
 Created 30 Nov. 2009
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

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one step:
  stepper.step(1);
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
  delay(500);
}

