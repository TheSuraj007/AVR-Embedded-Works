

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

// function to write command on LCD
void lcd_cmd(unsigned char cmd)
{
	lcdport = cmd;
	rs_low();		// rs = 0 to select the command register
	en_high();
	_delay_ms(1);
	en_low();
}

// function to write data on LCD
void lcd_data(unsigned char dat)
{
	lcdport = dat;
	rs_high();		// rs = 0 to select the command register
	en_high();
	_delay_ms(1);
	en_low();
}

void lcd_init()
{
	lcd_cmd(0x38); _delay_ms(5);
	lcd_cmd(0x02); _delay_ms(5);
	lcd_cmd(0x01); _delay_ms(5);
	lcd_cmd(0x0C); _delay_ms(5);
	lcd_cmd(0x06); _delay_ms(5);
	lcd_cmd(0x80); _delay_ms(5);
}

void cursorxy(char x, char y)
{
	if( ( x < 1 || x > 2) || (y < 1 || y > 16) )
	{
		x = 1;
		y = 1;
	}
	if(x == 1)
	lcd_cmd(0x7F+y);
	else
	lcd_cmd(0xBF+y);
}
//function to print any input value upto the desired digit on lcd
void lcd_print(char row, char coloumn, unsigned int value, int digits)
{
	unsigned int temp;
	unsigned int unit;
	unsigned int tens;
	unsigned int hundred;
	unsigned int thousand;
	unsigned int million;
	
	unsigned char flag=0;
	
	
	if(row==0||coloumn==0)
	{
		cursorxy(1,1);
	}
	else
	{
		cursorxy(row,coloumn);
	}
	if(digits==5 || flag==1)
	{
		million=value/10000+48;
		lcd_data(million);
		flag=1;
	}
	if(digits==4 || flag==1)
	{
		temp = value/1000;
		thousand = temp%10 + 48;
		lcd_data(thousand);
		flag=1;
	}
	if(digits==3 || flag==1)
	{
		temp = value/100;
		hundred = temp%10 + 48;
		lcd_data(hundred);
		flag=1;
	}
	if(digits==2 || flag==1)
	{
		temp = value/10;
		tens = temp%10 + 48;
		lcd_data(tens);
		flag=1;
	}
	if(digits==1 || flag==1)
	{
		unit = value%10 + 48;
		lcd_data(unit);
	}
	if(digits>5)
	{
		lcd_data('e');
	}
}

void lcd_out(char x, char y, char *str)
{
	cursorxy(x,y);
	while(*str)
	{
		lcd_data(*str);
		str++;
	}

}

int main(void)
{
	/* Replace with your application code */
	int a = 0;
	DDRB = 0xff; // 1111 1111
	DDRD |= (1 << 2);
	DDRD |= (1 << 3);
	DDRD &= ~(1 << 4);
	DDRD &= ~(1 << 5);
	
	PORTD |= (1<<4);   //PortD.4 Pull-UP
	PORTD |= (1<<5);   //PortD.5 Pull-UP
	
	lcd_init();
	lcd_out(1,1,"UP-DOWN Counter");
	lcd_print(2,1,a,5);
	
	while (1)
	{
		if((PIND & 0x10) == 0)   //
		{
			a++;
			lcd_print(2,1,a,5);
			_delay_ms(200);
		}
		
		if((PIND & 0x20) == 0)   //
		{
			a--;
			lcd_print(2,1,a,5);
			_delay_ms(200);
		}
		

	}
}
