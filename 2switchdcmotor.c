
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
void PWM_init(){
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3);
}

int main()
{
	DDRA=0XFF;
	DDRB=0XFF;
	DDRD&=~(1<<PD0);
	DDRD&=~(1<<PD1);
	PWM_init();
	
	PORTB=0<<PB0;
	while (1)
	{
			if((PIND&(1<<PD0))==0){
				OCR0=120;
				_delay_ms(1000);
				
			}
			if((PIND&(1<<PD1))==0){
				OCR0=200;
				_delay_ms(1000);
	
			}
		
	}
	
}

