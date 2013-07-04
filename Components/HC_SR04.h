//   HC_SR04.h
//
//   This was designed for use with the HC-SR04 Ultrasonic distance
//   sensor on the Raspberry Pi. Of all of the resources for the 
//   Raspberry Pi I couldn't find any examples or projects explaining
//   how to integrate the Raspberry Pi with the any distance sensors.
//
//
//   Created By: Jeff Treleaven
//   Created On: 6/25/2013
//
//---------------------------------------------------------------------\\

#ifndef HC_SR04
#define HC_SR04

/*
 * Returns a whole number distance in inches
 * from the sensor. 
 * Trigger - The GPIO pin attached to the
 *           trigger pin on the sensor.
 * Echo    - The GPIO pin attached to the 
 *           echo pin on the sensor.
 */
int getDistanceInches(int trigger, int echo);


/*
 * Returns a whole number distance in centimeters
 * from the sensor.
 * Trigger - As stated above...
 * Echo    - As stated above...
 */
int getDistanceCentimeters(int trigger, int echo);


/*
 * Returns a 6 decimal place precise value of the 
 * distance in inches from the distance sensor.
 * Trigger - As stated above...
 * Echo    - As stated above...
 */
float preciseDistanceInches(int trigger, int echo);


/*
 * Returns a 6 decimal place precise value of the
 * distance in centimeters from the distance
 * sensor.
 * Tigger - As stated above...
 * Echo   - As stated above...
 */
float preciseDistanceCentimeters(int trigger, int echo);

#endif