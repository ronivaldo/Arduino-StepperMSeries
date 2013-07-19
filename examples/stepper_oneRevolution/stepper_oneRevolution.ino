
/* 
 Stepper Motor Control - one revolution
 
 This program drives a unipolar or bipolar stepper motor.
 
 The motor driver is attached to digital pins 8,9 of the Arduino.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.  
 
 Changed by Ronivaldo Sampaio to M Series
 2013
 https://github.com/ronivaldo/Arduino-StepperMSeries
 
 Original:
 http://www.arduino.cc/en/Reference/Stepper
 This example code is in the public domain.
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
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

void setup() {
  // set the speed at 60 rpm:
  stepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  stepper.step(STEPS);
  delay(500);
  
   // step one revolution in the other direction:
  Serial.println("counterclockwise");
  stepper.step(-STEPS);
  delay(500); 
}

