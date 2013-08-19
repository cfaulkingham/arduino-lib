/*
  ULN2003.h - Library for ULN2003 Stepper Driver.
  Created by Colin Faulkingham, August 5, 2013.

  Created from the Orginal Code at,
  http://www.4tronix.co.uk/arduino/Stepper-Motors.php

  Description,
  This Arduino example demonstrates bidirectional operation of a 
  28BYJ-48, using a ULN2003 interface board to drive the stepper.
  The 28BYJ-48 motor is a 4-phase, 8-beat motor, geared down by
  a factor of 68. One bipolar winding is on motor pins 1 & 3 and
  the other on motor pins 2 & 4. The step angle is 5.625/64 and the 
  operating Frequency is 100pps. Current draw is 92mA. 
*/

#ifndef ULN2003_h
#define ULN2003_h

#include "Arduino.h"
class ULN2003
{
  public:
   	ULN2003(int motorPin1, int motorPin2, int motorPin3, int motorPin4);
   	void clockwise();
   	void anticlockwise();
  private:
  	void setOutput(int out);
    int _mp1;
 	int _mp2;
  	int _mp3;
   	int _mp4;
};

#endif

  