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
#include <util/delay.h>


int main(void)
{
	DDRA=0XFF;
	//DDRC=0X01;
	DDRD&=~(1<<PD0);
	DDRD&=~(1<<PD1);
	//DDRD=0X00;
    while (1) 
    {
		if((PIND&(1<<PD0))==0){
			for(int i=PA0;i<=PA7;i++){
				PORTA=1<<i;
				_delay_ms(500);
	
			}	
		}
		if((PIND&(1<<PD1))==0){
			for(int i=PA7;i<=PA0;i++){
				PORTA=1<<i;
				_delay_ms(500);
				
			}	
			
			
			
						
		}
    }
}

