/*
 * Usart_Recieve.cpp
 *
 * Created: 2/28/2016 08:54:15 PM
 * Author : HP PAVILION
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

volatile unsigned char data;
int main(void)
{
	
	/* Replace with your application code */

	DDRB=0xFF;//What to do with the RxD and TxD pin PD0 and PD1
	PORTD=(1<<1)|(1<<0);
	UBRR0H=(BAUDRATE>>8);
	UBRR0L=BAUDRATE;
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);//sETS THE rX AND tX PINS
	UCSR0C|=(1<<UPM01)|(1<<UPM00)|(1<<USBS0)|(1<<UCSZ00)|(1<<UCSZ01);//sETTING sTOP BIT=0,PARITY BIT AS EVEN,DATA BIT AS 8
	
	while (1)
	{
		while(!(UCSR0A&(1<<RXC0)))
		;//What does this means?
		data=UDR0;
		
		if(data=='a')
		{
			PORTB=0xFF;
		}
		
		
		
		
    }
}

