/*
  StepperMSeries.cpp - M Series Stepper library for Wiring/Arduino - Version 0.1
  
  Original library (0.1) by Tom Igoe
  http://www.arduino.cc/en/Tutorial/Stepper
  
  This is the Stepper library for Arduino to control signals for 
  Leadshine High Performance Microstepping M Series Drive.
  
  Version 0.1 is for single pulse (pulse/direction) mode only.

  To download from github (https://github.com/ronivaldo/Arduino-StepperMSeries), 
  click on the "Downloads" link in the upper right, click "Download as zip", 
  and get a zip file.  Unzip it and rename the directory 
  ronivaldo-Arduino-StepperMSeries-nnn to StepperMSeries

  To install, move the downloaded StepperMSeries directory to:
  arduino-1.x/libraries/StepperMSeries
  where arduino-1.x is your Arduino installation directory

  After installation you should have files such as:
  arduino-1.x/libraries/StepperMSeries/StepperMSeries.cpp

  For details on the library see the Wiki on github.

  For details on the drive see:
  http://www.leadshine.com/series.aspx?type=products&category=stepper-products&producttype=stepper-drives&series=M

  Copyright 2013 Ronivaldo Sampaio
 */


#include "Arduino.h"
#include "StepperMSeries.h"

/*
 * Sets which wires should control the motor.
 */
StepperMSeries::StepperMSeries(int number_of_steps, int pulse_pin, int direction_pin)
{
  this->step_number = 0;      // which step the motor is on
  this->speed = 0;        // the motor speed, in revolutions per minute
  this->direction = 0;      // motor direction
  this->last_step_time = 0;    // time stamp in ms of the last step taken
  this->number_of_steps = number_of_steps;    // total number of steps for this motor
  
  // Arduino pins for the driver control connection:
  this->pulse_pin = pulse_pin;
  this->direction_pin = direction_pin;

  // setup the pins on the microcontroller:
  pinMode(this->pulse_pin, OUTPUT);
  pinMode(this->direction_pin, OUTPUT);
}

/*
  Sets the speed in revs per minute

*/
void StepperMSeries::setSpeed(long whatSpeed)
{
  this->step_delay = 60L * 1000L / this->number_of_steps / whatSpeed;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative, 
   the motor moves in the reverse direction.
 */
void StepperMSeries::step(int steps_to_move)
{  
  int steps_left = abs(steps_to_move);  // how many steps to take
  
  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) {this->direction = 1;}
  if (steps_to_move < 0) {this->direction = 0;}
    
    
  // decrement the number of steps, moving one step each time:
  while(steps_left > 0) {
    // move only if the appropriate delay has passed:
    if (millis() - this->last_step_time >= this->step_delay) {
      // get the timeStamp of when you stepped:
      this->last_step_time = millis();
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      } 
      else { 
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor
      stepMotor();
    }
  }
}

/*
 * Moves the motor forward or backwards.
 */
void StepperMSeries::stepMotor()
{
  // forward direction
  if (this->direction == 1) {
    // set high to direction pin
	// clockwise direction
	digitalWrite(direction_pin, HIGH);
  // backwards direction
  } else {
    // set high to direction pin
	// counter-clock direction
	digitalWrite(direction_pin, LOW);
  }
  // give time to driver
  delay(1);
  // set high to pulse pin
  // if upward-rising edge mode, motor will step
  digitalWrite(pulse_pin, HIGH);
  // give time to driver
  delay(1);
  // set low to pulse pin
  // if downward-falling edge mode, motor will step
  digitalWrite(pulse_pin, LOW);
}

/*
  version() returns the version of the library:
*/
int StepperMSeries::version(void)
{
  return 1;
}
