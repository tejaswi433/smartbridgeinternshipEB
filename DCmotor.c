

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <stdlib.h>


int main(void)
{
	DDRA=0XFF;
	
    while (1) 
    {
		PORTA=0x01;
	    _delay_ms(10000);

        PORTA=0x00;
		_delay_ms(1000);
        PORTA=0x02;
		_delay_ms(10000);
        PORTA=0x00;
       _delay_ms(1000);
    }
}

