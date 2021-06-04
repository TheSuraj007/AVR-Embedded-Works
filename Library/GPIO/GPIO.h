
#define SET_BIT(byte,bit) (byte |=(1<<bit))
#define CLEAR_BIT(byte,bit) (byte &= ~(1<<bit))
#define IS_SET(byte,bit) ((byte) & (1<<bit))

//Macro variable for operating MODE in pinMode()
#define OUTPUT 1
#define INPUT 0

//Macro variable for equating State in DigitalWrite()
#define HIGH 1
#define LOW 0

#include "GPIO.cpp"