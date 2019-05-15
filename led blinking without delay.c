

#include <avr/io.h>
#define LED PB0

int main(void)
{
    uint8_t timerOverflowCount=0;
	DDRB=0XFF;
	TCNT0=0X00;
	TCCR0=(1<<CS00)|(1<<CS02);
    while (1) 
    {
		while((TIFR&0X01)==0);
		TCNT0=0X00;
		TIFR =0X01;
		timerOverflowCount++;
		if(timerOverflowCount>=25){
			PORTB ^= (0X01<<LED);
			timerOverflowCount=0;
		}
    }
}

