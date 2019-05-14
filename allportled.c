/*
 * GccApplication1.c
 *
 * Created: 09-05-2019 14:16:09
 * Author : Teja
 */ 
#ifndef F_CPU
#define F_CPU 1600000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=1<<DDA7;
	DDRB=1<<DDB7;
	DDRC=1<<DDC7;
	DDRD=1<<DDD7;
    while (1) 
    {
		PORTA|=1<<PIN7;
		PORTB|=1<<PIN7;
		PORTC|=1<<PIN7;
		PORTD|=1<<PIN7;
		
    }
}

