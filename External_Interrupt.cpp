/*
 * External_Interrupt.cpp
 *
 * Created: 2/27/2016 06:09:01 PM
 * Author : HP PAVILION
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	//DDRD=(0<<2);//int0 pin is pin 2 od port d
	//PORTD=(1<<2);
	cli();
	
	sei();
	DDRB=(1<<0);
	PORTD=(1<<2);
	EIMSK=(1<<INT0);
	EICRA=(0<<ISC00)|(1<<ISC01);
    while (1) 
    {
		
    }
}

ISR(INT0_vect)
{
	PORTB^=(1<<0);
	
}
