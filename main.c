/*
 * Beeper.c
 *
 * Created: 25.04.2023 16:20:55
 * Author : Ralfw
 */ 

#include <avr/io.h>
#define F_CPU 20000000UL
#define MHZ_1 1000000UL

#include <util/delay.h>
#define BEEPERPORT	PORTC
#define BEEPERDDR	DDRC
#define BEEPERPINR  PINC
#define BEEPERPIN   PORTC0

#define TON_1000HZ MHZ_1/1000/2


void initBeeper()
{
	BEEPERDDR  |=(1<<BEEPERPIN);
	BEEPERPORT &=~(1<<BEEPERPIN);
}


void beep()
{
	for(uint16_t i =0;i<2000;i++)
	{
	//Ansprechen des PIN Registers lässt den 
	//Ausgang von High nach Low kippen
	BEEPERPINR =(1<<BEEPERPIN);
	_delay_us(TON_1000HZ); 
	}
}

int main(void)
{
initBeeper();


	
    /* Replace with your application code */
    while (1) 
    {
	beep();
	_delay_ms(1000);
		
		
    }
}

