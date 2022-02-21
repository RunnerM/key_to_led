/*
 * key_driver.c
 *
 * Created: 2022-02-18 1:29:07 PM
 *  Author: pente
 */ 
#include "key_driver.h"

void init_keys()
{
	DDRC &= ~( 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 );
	PORTC = 0xFC;
}


uint8_t get_key(uint8_t key_no)
{
	if (PINC & _BV(key_no)>0)
	{
		return 0x80;
	}
	return 0x00;
	
}