// --------------------DDRX------------------------------
void pinMode(uint8_t Pin, uint8_t volatile *pin_data_direction_register, bool Mode)
{
	if (Mode == OUTPUT)
	{
		*pin_data_direction_register |= (1<< Pin);
	}
	else if(Mode == INPUT)
	{
		*pin_data_direction_register &= ~(1<<Pin);
	}
}

//----------------------PORTX--------------------------------
void digitalWrite(uint8_t Pin, uint8_t volatile *port_data_pin_register, bool State)
{
	if (State == HIGH)
	{
		*port_data_pin_register |= (1 << Pin);
	}
	else if (State == LOW)
	{
		*port_data_pin_register &= ~(1 << Pin);
	}
}

//-----------------------PINX---------------------------------
uint8_t digitalRead(uint8_t Pin, uint8_t volatile *port_input_pin_register)
{
	return ((*port_input_pin_register) & (1 << Pin));
}

