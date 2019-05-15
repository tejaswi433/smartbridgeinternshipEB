/*
 * GccApplication8.c
 *
 * Created: 10-05-2019 14:17:52
 * Author : Teja
 */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)

{
	DDRC = 0XFF;
	DDRD = 0XFF;
	_delay_ms(500);
	send_command(0X01);
	send_command(0X38);
	send_command(0X0E);

	
	send_character(0X53);
	send_character(0X6F);
	send_character(0X68);
	send_character(0X61);
	send_character(0X69);
	send_character(0X6C);



    /* Replace with your application code */
  /*  while (1) 
    {
    }*/
}
void send_command(unsigned char command){
	PORTC =command;
	PORTD &= (1<<RS);
	PORTD |= (1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
	
}
void send_character(unsigned char character){
	PORTC =character;
	PORTD |= (1<<RS);
	PORTD |= (1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
	
	
}


