#ifndef F_CPU
#define F_CPU 1600000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=1<<DDA0;
	DDRA=1<<DDA2;
	DDRA=1<<DDA4;
	DDRA=1<<DDA6;
	while (1)
	{
		PORTA=0X55;
        _delay_ms(1000);
		PORTA=0X00;
		 _delay_ms(1000);

		
	}
}

