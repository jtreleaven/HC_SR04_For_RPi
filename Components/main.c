// main.c
//
// This is just a test for the header file.

#include <bcm2835.h>
#include <stdio.h>
#include "HC_SR04.h"

#define trig RPI_V2_GPIO_P1_11
#define echo RPI_V2_GPIO_P1_15

#define __STDC_FORMAT_MACROS

int main(int argc, char **argv)
{
	printf("Testing getDistance for Integers...\n");
	
	// Test integer methods
	int wnInt = getDistanceInches(trig, echo);
	int wnCent = getDistanceCentimeters(trig, echo);
	
	printf("Inches = %d\n", wnInt);
	printf("Centimeters = %d\n", wnCent);
	
	// Test precise float methods
	float preInt = preciseDistanceInches(trig, echo);
	float preCent = preciseDistanceCentimeters(trig, echo);
	
	printf("Inches = %f\n", preInt);
	printf("Centimeters = %f\n", preCent);
	
	return 0;
}
