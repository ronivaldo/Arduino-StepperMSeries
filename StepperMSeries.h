/*
  StepperMSeries.cpp - M Series Stepper library for Wiring/Arduino - Version 0.1
  
  Original library     (0.1) by Tom Igoe
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

// ensure this library description is only included once
#ifndef StepperMSeries_h
#define StepperMSeries_h

// library interface description
class StepperMSeries {
  public:
    // constructors:
    StepperMSeries(int number_of_steps, int pulse_pin, int direction_pin);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor();
    
    int direction;        // Direction of rotation
    int speed;          // Speed in RPMs
    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int step_number;        // which step the motor is on
    
    // driver pin numbers:
    int pulse_pin;
    int direction_pin;
    
    long last_step_time;      // time stamp in ms of when the last step was taken
};

#endif

