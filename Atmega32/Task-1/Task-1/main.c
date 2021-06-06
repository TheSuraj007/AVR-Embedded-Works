/*
 * Task-1.c
 *
 * Created: 2/21/2021 8:13:54 PM
 * Author : Surajkumar
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB &= ~(1<<3); //PortB.3 I/P
	DDRB &= ~(1<<5); //PortB.5 I/P
	DDRD |=(1<<0);   //PortD.0 O/P
	DDRD |=(1<<5);   //PortD.5 O/P
	
	PORTB |= (1<<3);   //PortB.3 Pull-UP
	PORTB |= (1<<5);   //PortB.5 Pull-UP
	
    while (1) 
    {
		
		if((PINB & 0x20) == 0)
		{
			PORTD |= (1<<0);
		}
		
		if((PINB & 0x08) == 0)
		{
			PORTD |=(1<<5);
		}
		else
		{
			PORTD &= ~(1<<0);
			PORTD &= ~(1<<5);
		}
    }
}

