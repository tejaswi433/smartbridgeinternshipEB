#ifndef F_CPU
#define F_CPU 1600000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0XFF;
	while (1)
	{
		PORTA=1<<PA0;
		_delay_ms(1000);
		PORTA=1<<PA2;
		_delay_ms(1000);
		PORTA=1<<PA4;
		_delay_ms(1000);
		PORTA=1<<PA6;
		_delay_ms(1000);
		
		PORTA=1<<PA1;
		PORTA=1<<PA3;
		PORTA=1<<PA5;
		PORTA=1<<PA7;
		_delay_ms(1000);
		PORTA=0<<PA1;
		PORTA=0<<PA3;
		PORTA=0<<PA5;
		PORTA=0<<PA7;
		_delay_ms(1000);
		

	}
}

