#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define UBRR_VAL F_CPU/16/BAUD-1

void usart_init (unsigned int speed)
{
	UBRRH=(unsigned char)(speed>>8);
	UBRRL=(unsigned char) speed;
	UCSRA=0x00;
	UCSRB=(1<<TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

int main(void)
{
	usart_init(UBRR_VAL);
	char i=0;
    while(1)
    {
     UDR=i;
	 _delay_ms(1000);
	 i+=1;   
    }
}