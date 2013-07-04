//   HC_SR04.c0
//
//   This was designed for use with the HC-SR04 Ultrasonic distance
//   sensor on the Raspberry Pi. Of all of the resources for the 
//   Raspberry Pi I couldn't find any examples or projects explaining
//   how to integrate the Raspberry Pi with the any distance sensors.
//	 So I decided it was best to make my own and share it so that I
//   may be able to save those the trouble of reinventing the wheel. 
//
//   Created By: Jeff Treleaven
//   Created On: 6/25/2013
//
//---------------------------------------------------------------------\\

#include <bcm2835.h>
#include "HC_SR04.h"

/*
 *  This is a local subroutine function used in each method to 
 *  initiate pulses out of the sensor and return the pulse with
 *  of the returned ultrasonic signal.
 *  Trigger - The GPIO pin attached to the trigger pin on the 
 *            sensor.
 *  Echo    - The GPIO pin attached to the echo pin on the
 *            sensor.
 */
static uint64_t cyclePulse(int trigger, int echo)
{
        if (!bcm2835_init())
	        return 1;
      
	// Set RPi pin echo to be an input pin
	bcm2835_gpio_fsel(echo, BCM2835_GPIO_FSEL_INPT);
	// Set RPi pin P1-11 to be an output pin
	bcm2835_gpio_fsel(trigger, BCM2835_GPIO_FSEL_OUTP);
	
	
	// Declare the unsigned int timer variables to measure pulses
	uint64_t width, begin, start, end;
	int max = 80, check;

	begin = bcm2835_st_read();
	
	// Emit pulse for 10 microseconds
	bcm2835_gpio_write(trigger, HIGH); // Set trigger state HIGH
	bcm2835_delayMicroseconds(10);  // Wait 10 microseconds
	bcm2835_gpio_write(trigger, LOW);  // Set trigger state LOW
	
	// Infinite loop until a pulse is recieved
	while(bcm2835_gpio_lev(echo) == LOW && check < max) 
	{
	        start = bcm2835_st_read();
		check = (int) begin - start;
	}
		
	// Loop and delay for one microsecond until falling edge detected
	while(bcm2835_gpio_lev(echo) == HIGH)
	{
		bcm2835_delayMicroseconds(1);
	}
	// Record the ending time of the pulse to get the pulse width
	end = bcm2835_st_read();
	
	// Get the final with of the pulse
	width = end - start;

	//Close the bcm2835 bridge
	bcm2835_close();

	// Return the total width of the returned pulse
	return width;
}

/*
 * Returns a whole number distance in inches
 * from the sensor. 
 * Trigger - The GPIO pin attached to the
 *           trigger pin on the sensor.
 * Echo    - The GPIO pin attached to the 
 *           echo pin on the sensor.
 */
int getDistanceInches(int trigger, int echo)
{
        return (int) cyclePulse(trigger, echo) / 144;
}

/*
 * Returns a whole number distance in centimeters
 * from the sensor.
 * Trigger - As stated above...
 * Echo    - As stated above...
 */
int getDistanceCentimeters(int trigger, int echo)
{
        return (int) cyclePulse(trigger, echo) / 55.5;
}


/*
 * Returns a 6 decimal place precise value of the 
 * distance in inches from the distance sensor.
 * Trigger - As stated above...
 * Echo    - As stated above...
 */
float preciseDistanceInches(int trigger, int echo)
{
        return (float) cyclePulse(trigger, echo) / 144;
}


/*
 * Returns a 6 decimal place precise value of the
 * distance in centimeters from the distance
 * sensor.
 * Tigger - As stated above...
 * Echo   - As stated above...
 */
float preciseDistanceCentimeters(int trigger, int echo)
{
        return (float) cyclePulse(trigger, echo) / 55.5;
}
