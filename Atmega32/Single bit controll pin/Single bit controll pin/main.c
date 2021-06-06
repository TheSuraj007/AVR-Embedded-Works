
#define F_CPU 1600000L
#include <avr/io.h>
#include <util/delay.h>

//#define  led_on() PORTD |=(1<<5)
//#define  led_off() PORTD &=~(1<<5)

int main(void)
{
	//DDRD |=(1<<5);
	DDRD =0xff;
    while (1) 
    {
		//led_on();
		PORTD = 0xff;
		_delay_ms (1000);
		//led_off();
		PORTD = 0x00;
		_delay_ms(1000);
    }
}

