/*
  ULN2003.cpp - Library for ULN2003 Stepper Driver.
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

#include "Arduino.h"
#include "ULN2003.h"

int motor = 1200;  //variable to set stepper speed
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

ULN2003::ULN2003(int motorPin1, int motorPin2, int motorPin3, int motorPin4)
{
    _mp1 = motorPin1;
    _mp2 = motorPin2;
    _mp3 = motorPin3;
    _mp4 = motorPin4;

	pinMode(motorPin1, OUTPUT);
	pinMode(motorPin2, OUTPUT);
	pinMode(motorPin3, OUTPUT);
	pinMode(motorPin4, OUTPUT);

}
//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void ULN2003::anticlockwise()
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motor);
  }
}

void ULN2003::clockwise()
{
  for(int i = 7; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motor);
  }
}

void ULN2003::setOutput(int out)
{
  digitalWrite(_mp1, bitRead(lookup[out], 0));
  digitalWrite(_mp2, bitRead(lookup[out], 1));
  digitalWrite(_mp3, bitRead(lookup[out], 2));
  digitalWrite(_mp4, bitRead(lookup[out], 3));
}

