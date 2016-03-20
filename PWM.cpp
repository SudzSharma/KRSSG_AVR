/*
 * pwm.cpp
 *
 * Created: 2/27/2016 04:53:58 PM
 * Author : HP PAVILION
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRD=(1<<6);//setting The Pin 6 as output.
	TCCR0A=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);//set  OCR0A at compare match and fast pwm mode.
	TCCR0B=(1<<CS00);//Starting the clock without The prescaling Value.
	
	
	while(1)
	{
		TCNT0=0;//Starts The Timer.
		
		
		for(int i=1;i<6;i++)
		{
			OCR0A=i*51;
			_delay_ms(1000);
			
		}
		
	}
	
}

