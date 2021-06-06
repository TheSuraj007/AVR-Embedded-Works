
#define F_CPU 1600000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	DDRD |= (1<<7);
    /* Replace with your application code */
    while (1) 
    {
		
		PORTD |= (1<<7);
		_delay_ms(1000);
		PORTD &= ~(1<<7);
		_delay_ms(1000);
    }
}

