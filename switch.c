/*
 * GccApplication6.c
 *
 * Created: 10-05-2019 11:20:17
 * Author : Teja
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include<util/delay.h>

u
int main(void)
{
	DDRC|=(1<<PC0);
	//DDRC=0X01;
	DDRD&=~(1<<PD0);
	//DDRD=0X00;
    while (1) 
    {
		if((PIND&(1<<PD0))==0){
			PORTC|=1<<PC0;
			_delay_ms(3000);
			PORTC&=~(1<<PC0);
			
		}
		
    }
}

