
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <stdlib.h>
#define enable 5
#define registerselection 7
void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);
void PWM_init(){
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3);
}


int main(void)
{
	DDRC = 0XFF;
	DDRA = 0X00;
	DDRD = 0XFF;
	DDRB = 0XFF;
	_delay_ms(50);
	PWM_init();

	ADMUX|=(1<<REFS0)|(1<<REFS1);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA=0;
	char SHOWA[3];
	send_a_command(0X01);
	_delay_ms(50);
	send_a_command(0X38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA|=(1<<ADSC);
	PORTB=0<<PB0;
	while (1)
	{
		COUNTA=ADC/4;
		send_a_string("Smartbridge");
		send_a_command(0X80+0X40+0);
		send_a_string("Resistance=");
		send_a_command(0X80+0X40+11);
		itoa(COUNTA,SHOWA,10);
		send_a_string(SHOWA);
		send_a_string("  ");
		send_a_command(0X80+0);
		
		OCR0=COUNTA;
		
	}
}
void send_a_command(unsigned char command){
	PORTC = command;
	PORTD&=~(1<<registerselection);
	PORTD|=1<<enable;
	_delay_ms(20);
	PORTD&=~1<<enable;
	PORTC=0;
}
void send_a_character(unsigned char character){
	PORTC = character;
	PORTD|=(1<<registerselection);
	PORTD|=1<<enable;
	_delay_ms(20);
	PORTD&=~1<<enable;
	PORTC=0;
}
void send_a_string(char *string_of_characters){
	while(*string_of_characters>0){
		send_a_character(*string_of_characters++);
	}
	
}
