

#include <avr/io.h>
#define F_CPU 1600000L

int main(void)
{
DDRB = 0xFF;
PORTB = 0b11110111;
    while (1) 
    {
		PORTB |= ~(1<<4);		
				
    }
	return 0;
}

