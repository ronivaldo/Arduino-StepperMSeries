/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 *
 *
 * Changed by Ronivaldo Sampaio to M Series
 * 2013
 * https://github.com/ronivaldo/Arduino-StepperMSeries
 *
 * Original:
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
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

// the previous reading from the analog input
int previous = 0;

void setup()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);
}

void loop()
{
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
}