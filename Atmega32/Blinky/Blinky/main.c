/*
 * Blinky.c
 *
 * Created: 2/14/2021 11:46:48 AM
 * Author : Surajkumar
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

#define Led PB5
#define Set_Bit(Port_No,Pin_No) (Port_No |= (1<< Pin_No))
#define Clear_Bit(Port_No,Pin_No) (Port_No &= ~(1<<Pin_No))

int main(void)
{	
	DDRB = 0xff;
   
    while (1) 
    {		
		Set_Bit(PORTB,Led);
		_delay_ms(1000);
		Clear_Bit(PORTB,Led);
		_delay_ms(1000);
    }
}

