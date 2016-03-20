/*
 * Interrupts.cpp
 *
 * Created: 2/26/2016 08:22:07 PM
 * Author : HP PAVILION
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

volatile uint32_t ovf=0;
int main(void)
{
    /* Replace with your application code */
	DDRD=(1<<4);
	DDRC=(1<<5);
	PORTD=(1<<4);
	PORTC=(1<<5);
		TCCR0B=(1<<CS00)|(1<<CS02);
		TIMSK0=(1<<TOIE0);
		sei();

    while (1) 
    {
		ovf=0;
		TCNT0=0;
		while(ovf<306)
		{
			
		}
		TCNT0=0;
		while(TCNT0<96)
		{
			
		}
     PORTD=PORTD^(1<<4);
	 ovf=0;		
    }
}

ISR(TIMER0_OVF_vect)
{
ovf++;	
	//PORTC^=(1<<5);
}