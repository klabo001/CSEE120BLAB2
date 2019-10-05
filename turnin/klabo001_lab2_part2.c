/*	Author: klabo001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
 /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's pins as outputs Initialize to 0x00
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A
    unsigned char tmpA1 = 0x00;
    while (1) {
		//1) Read Input
		tmpA0 = PINA & 0x01; // mask to check rightmost bit 
		tmpA1 = PINA & 0x02; //mask to check second to the rightmost bit
		
		//2) Perform Computation	
		if (tmpA0 == 0x01 && tmpA1 == 0x00) //Checks if A1A0 = 01
		{
			tmpB = (tmpB & 0xFC) | 0x01; // sets tmpB to bbbbbb01
										// clear rightmost 2 bits, then set to 01
		}
		else 
		{
			tmpB = (tmpB & 0xFC) | 0x00; // sets tmpB to bbbbbb00
		}
		//3) Write Output
		PORTB = tmpB;
    }
    return 0;
}
