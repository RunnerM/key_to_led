/*
 * led_driver.c
 *
 * Created: 2022-02-18 12:43:13 PM
 *  Author: pente
 */ 
#include "led_driver.h"

void init_leds() {
	DDRA = 0xFF;
	PORTA = 0xFF;
}
void set_led(uint8_t led_no, uint8_t state)
{
	PORTA |= state << led_no;
}