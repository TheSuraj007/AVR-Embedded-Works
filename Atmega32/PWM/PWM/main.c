/*
 * PWM.c
 *
 * Created: 3/5/2021 10:26:05 AM
 * Author : Surajkumar
 */ 

#include <avr/io.h>
#define F_CPU 1600000L
#include <avr/interrupt.h>
#include <util/delay.h>

double dutyCycle = 0;

int main(void)
{ 
	
	
    DDRD = (1<< PORTD6);
	TCCR0A = (1<< COM0A1)|(1<<WGM00)|(1<<WGM01); //Clear OC0A on Compare Match, set OC0A at BOTTOM,(non-inverting mode).
				   		                         //: Waveform Generation Mode => Fast PWM 
	TIMSK0 = (1<<TOIE0);											 
	OCR0A = (dutyCycle/100.0)*255;
	
	sei(); 											 
	TCCR0B = (1<<CS00);							 //clkI/O/(No prescaling)
	
    while (1) 
    {
		_delay_ms(100);
		dutyCycle +=  10;
		if (dutyCycle >100)
		{
			dutyCycle = 0;
		}
    }
}

ISR(TIMER0_OVF_vect)
{
	OCR0A = (dutyCycle/100.0)*255;
}


