
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
char buffer[10];
void USARTInit(uint16_t ubrr_value)
{
	UBRRL =ubrr_value;
	UBRRH =(ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRB=(1<<RXEN)|(1<<TXEN);
}
char USARTReadChar()
{
	while(!(UCSRA&(1<<RXC)))
	{
		
	}
	
	return UDR;
}
void USARTWriteChar(char data)
{
	while(!(UCSRA&(1<<UDRE))){
		
	}
	UDR =data;
	
}
int main(void)
{
	USARTInit(77);
	DDRB = 0XFF;
	char data;
    while (1) 
    {
		data = USARTReadChar();
		if(data=='1'){
			PORTB=1<<PB0;
		
		} 
		if(data == '2'){
			PORTB=0<<PB0;

         }
		 if(data=='3'){
			PORTB=1<<PB1;
		 }
		 if(data=='4'){
			PORTB=0<<PB0;
		 }
	}
	return 0;
}

