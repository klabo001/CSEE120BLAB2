/*	Author: klabo001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    
    /* Insert your solution below */
   
    while (1) {
		//1) Read Input
		tmpA = PINA & 0x01;
		//2) Perform Computation
		//if PA0 = 1, set PB1PB0 = 0, else = 10
		
		if (tmpA == 0x01)
		{
			tmpB = (tmpB & 0xFC) | 0x01; // sets tmpB to bbbbbb01
										// clear rightmost 2 bits, then set to 01
		}
		else 
		{
			tmpB = (tmpB & 0xFC) | 0x02; // sets tmpB to bbbbbb10
		}
		//3) Write Output
		PORTB = tmpB;
    }
    return 0;
}
