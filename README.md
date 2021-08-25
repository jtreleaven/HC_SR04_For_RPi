HC_SR04_For_RPi
===============

A C Macro for easy use  and interfacing of the HC_SR04 Ultrasonic Distance sensor on the Raspberry Pi. This was built on
the bcm2835 C library that allows access the Raspberry Pi's GPIO pins, internal clock, etc.

How to use Macro
================

  1) Either turn on and open the terminal on your Pi or ssh into your Pi. Watch the video found [here](http://www.youtube.com/watch?v=h89ZL0YWPok) from time 1:30 to 5:00 for instructions on how to install the [bcm2835](http://www.airspayce.com/mikem/bcm2835/index.html) library.
      
  2) Next download or copy the HC_SR04.c, HC_SR04.h, and the main.c files above into what ever directory you want
     to use on your raspberry pi.
     
  3) Next compile them by running the command below:
     ```
     gcc -o example main.c HC_SR04.c -l bcm2835
     ```
  
  4) Connect the trigger pin of the HC-SR04 sensor to Pin 11 (GPIO 17) on the raspberry pi and connect the echo pin on the 
     sensor to Pin 15 (GPIO 22) on the pi. Also connect +5V and GND either from the pi or an external power supply.
     
  5) To test this, just type:
     ```
     sudo ./example
     ```
