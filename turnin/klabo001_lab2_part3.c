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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's pins as outputs Initialize to 0x00
    unsigned char cntavail = 0;
    unsigned char parked = 0;
    unsigned char spaceavail = 4;
    
    while (1) {
		//1) Read Input
		parked = (PINA & 0x01) + ((PINA>>1) & 0x01)+ ((PINA>>2) & 0x01)+((PINA>>3) & 0x01);overed = (PINA & 0x01) + ((PINA>>1) & 0x01)+ ((PINA>>2) & 0x01)+((PINA>>3) & 0x01);
		//2) Perform Computation	
		cntavail = spaceavail - parked;
		//3) Write Output
		
		if (cntavail==0 )
		{
			cntavail = cntavail | 0x80; 
		}
		
		PORTC = cntavail;
    }
    return 0;
}
