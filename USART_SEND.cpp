/*
 * Usart-Code.cpp
 *
 * Created: 2/28/2016 06:13:10 PM
 * Author : HP PAVILION
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

volatile unsigned char data='a';
int main(void)
{
	
	/* Replace with your application code */

	//DDRD=(1<<1);//What to do with the RxD and TxD pin PD0 and PD1
	PORTD=(1<<1)|(1<<0);
	UBRR0H=(BAUDRATE>>8);
	UBRR0L=BAUDRATE;
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);//sETS THE rX AND tX PINS
	UCSR0C|=(1<<UPM01)|(1<<UCSZ00)|(1<<UCSZ01);//sETTING sTOP BIT=0,PARITY BIT AS EVEN,DATA BIT AS 8
	
	    while (1) 
    {
		while(!(UCSR0A&(1<<TXC0)))
		UDR0=data;
		
		_delay_ms(1000);
		
    }
}

