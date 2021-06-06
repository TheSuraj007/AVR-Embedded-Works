/*
 * Blinky.c
 *
 * Created: 2/14/2021 11:46:48 AM
 * Author : Surajkumar
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xff;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA = 0xAA;
		_delay_ms(200);
		PORTA = 0x55;
		_delay_ms(200);
		
		
    }
}

