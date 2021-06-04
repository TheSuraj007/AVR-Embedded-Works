/*
	* Created: 3/17/2021 5:08:29 PM
	* Author : Surajkumar

*/


#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>


char Temp;
char Buff[50];
bool flag = true;
int i = 0 ;
int k;
int j;

void uart_update(char data);
void uart_write(char data);
void uart_write_text(char *str);

// expected uart value, 9600
void uart_init()
{
	UBRR0=103;
	/*Set Frame Format
	Asynchronous mode
	No Parity
	1 StopBit
	char size 8
	*/
	UCSR0C=(3<<UCSZ00);

	/*Enable Interrupts
	RXCIE- Receive complete
	UDRIE- Data register empty

	Enable The receiver and transmitter

	*/
	UCSR0B=(1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	//UCSRB=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	
	DDRB = 0xff;
	
	sei();
	

}

ISR(USART_RX_vect)
{
  uart_update(UDR0);
}

void uart_update(char data)
{
	if (data != '\n' && flag)
	{
		Buff[i] = data;
		uart_write(Buff[i]);
		i++;
		
	}
	if (data == '\n')
	{
		flag = false;
	}
	
	
}

char uart_read_text(char *data_send)
{
	if (flag == false)
	{		
		for (k=0; k <= i; k++)
		{
			data_send[k] = Buff[k];
			if (k == i)
			{
				for (k=0; k <= i; k++)
				{
					Buff[k] = 0;
					
				}
				flag = true;
				i = 0;
			}
		}
	}
}

void uart_write(char data)
{
	//Wait For Transmitter to become empty so its ready to receive new data
	while( !(UCSR0A & (1<<UDRE0)));
	//Now write
	UDR0=data;
}

void uart_write_text(char *str)
{
	while((*str)!='\0')
	{
		uart_write(*str);
		str++;
	}
}


char card1[] = "LED is ON";
char card2[] = "LED is OFF";
char card3[] = "FAN is ON";
char card4[] = "FAN is OFF";
char card5[] = "All appliances OFF";
int main(void)
{
    /* Replace with your application code */
	char rxd[15] ="";
	int i;
	int a = 352;
	uart_init();
	_delay_ms(2000);
	uart_write_text("Code Started\r\n");
	uart_write(35);
	
	DDRB = 0xFF;
	

    while (1) 
    {
		_delay_ms(1000);
		uart_read_text(rxd);
 		
		
		if(strcmp(rxd, card1) == 0)
		{
			uart_write_text("\r\nLED is ON\r\n");
			PORTB |= (1<<1);
		}
		else if(strcmp(rxd, card2) == 0)
		{
			uart_write_text("\r\nLED is OFF\r\n");
				PORTB &= ~(1<<1);
		}
		else if(strcmp(rxd, card3) == 0)
		{
			uart_write_text("\r\nFAN is ON\r\n");
			PORTB |= (1<<2);
		}
		else if(strcmp(rxd, card4) == 0)
		{
			uart_write_text("\r\nFAN is OFF\r\n");
			PORTB &= ~(1<<2);
		}
		else if(strcmp(rxd, card5) == 0)
		{
			uart_write_text("\r\nAll appliances OFF\r\n");
			PORTB = 0x00;
		}
		
	}
}




