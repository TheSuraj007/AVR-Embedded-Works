#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1<<2);
#define rs_low() PORTD &= ~(1<<2);

#define en_high() PORTD |= (1<<3);
#define en_low() PORTD &= ~(1<<3);

#define lcdport PORTB


void lcd_cmd(unsigned char cmd)
{
	lcdport = cmd;
	rs_low();
	_delay_ms(2);
	en_high();
	_delay_ms(2);
	en_low();
}

void lcd_data(unsigned char data)
{
	lcdport = data;
	rs_high();
	_delay_ms(2);
	en_high();
	_delay_ms(2);
	en_low();
}

void lcd_print(char *printData)
{
	while(*printData)
	{
		lcd_data(*printData);
		printData++;
	}
}


void lcd_init()     //Function to prepare the LCD  and get it ready
{
	lcd_cmd(0x38);  // for _using 2 lines and 5X7 matrix of LCD
	_delay_ms(5);
	
	lcd_cmd(0x02);  //Return home
	_delay_ms(5);
	
	lcd_cmd(0x01);  //Clear display screen
	_delay_ms(5);
	
	lcd_cmd(0x0C);  //Display ON, cursor OFF
	_delay_ms(5);
	
	lcd_cmd(0x06);  //Increment cursor (shift cursor to right)
	_delay_ms(5);
	
	lcd_cmd(0x80);  //Force cursor to the beginning of the first line
	_delay_ms(5);
	
	
}
int main(void)
{
	DDRB = 0Xff;
	DDRD |= (1<<2);
	DDRD |= (1<<3);
	
	lcd_init();
	lcd_print("Welcome to AVR");
	
	while (1);
}
