
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1<<7);
	DDRB &= ~(1<<6);

    while (1) 
    {
		PORTB ^= (1<<7);
		if (PINB & (1<<6))
		{
			_delay_ms(100);
		}else{
			_delay_ms(1000);
		}
    }
}

