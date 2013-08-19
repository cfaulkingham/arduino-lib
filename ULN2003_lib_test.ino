#include <ULN2003.h>

// This Arduino example demonstrates bidirectional operation of a 
// 28BYJ-48, using a ULN2003 interface board to drive the stepper.
// The 28BYJ-48 motor is a 4-phase, 8-beat motor, geared down by
// a factor of 68. One bipolar winding is on motor pins 1 & 3 and
// the other on motor pins 2 & 4. The step angle is 5.625/64 and the 
// operating Frequency is 100pps. Current draw is 92mA. 
////////////////////////////////////////////////

//declare variables for the motor pins
int motorPin1 = 2;//8;    // Blue   - 28BYJ48 pin 1
int motorPin2 = 4;//9;    // Pink   - 28BYJ48 pin 2
int motorPin3 = 6;//10;    // Yellow - 28BYJ48 pin 3
int motorPin4 = 9;//11;    // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
ULN2003 drv(2,4,6,9);
int motorSpeed = 1200;  //variable to set stepper speed
int count = 0;          // count of steps made
int countsperrev = 512; // number of steps per full revolution

//////////////////////////////////////////////////////////////////////////////
void setup() {
  //Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
void loop(){
  if(count < countsperrev )
    drv.clockwise();
  else if (count == countsperrev * 2)
    count = 0;
  else
    drv.anticlockwise();
  count++;
}

