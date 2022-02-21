/*
 * key_to_led.c
 *
 * Created: 2022-02-18 12:38:57 PM
 * Author : pente
 */ 

#include <avr/io.h>
#include "drivers/key_driver.h"
#include "drivers/led_driver.h"
uint8_t key1;
uint8_t key2;



int main(void)
{
	init_leds();
	while (1)
	{
		set_led(0,1);
	}
	
    /* Replace with your application code */
    /*while (1) 
    {
		key1=get_key(1);
		key2=get_key(2);
		if ((key1 & key2)==0x80)
		{
			set_led(0,1);
		}
		else{
			set_led(0,0);
		}
		if((key1 | key2)==0x80)
		{
			set_led(1,1);
		}
		else{
			set_led(1,0);
		}
    }*/
}

