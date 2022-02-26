/*
 * key_to_led.c
 *
 * Created: 2022-02-18 12:38:57 PM
 * Author : pente
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "drivers/key_driver.h"
#include "drivers/led_driver.h"


volatile uint8_t key1;
volatile uint8_t key2;
volatile uint8_t scan_result;

void logicgates();
void buttonlightbar();



int main(void)
{
	init_leds();
	init_keys();
	logicgates();
	//buttonlightbar();
}

void logicgates(){
	while (1)
	{
		key1=get_key(1);
		key2=get_key(2);
		//AND
		if ((key1 & key2)==1){
			set_led(1,1);
		}
		else{
			set_led(1,0);
		}
		//OR
		if((key1 | key2)==1){
			set_led(2,1);
		}
		else{
			set_led(2,0);
		}
		//XOR
		if((key1 ^ key2)==1){
			set_led(3,1);
		}
		else{
			set_led(3,0);
		}
		//NAND
		if((key1 & key2)==0){
			set_led(4,1);
		}
		else{
			set_led(4,0);
		}
		//NOR
		if((key1 | key2)==0){
			set_led(5,1);
		}
		else{
			set_led(5,0);
		}
		//XNOR
		if((key1 ^ key2)==0){
			set_led(6,1);
		}
		else{
			set_led(6,0);
		}
	}
}
void buttonlightbar(){
	while(1){
		scan_result=scan_key();
	if(scan_result!=0){
		lightbar(scan_result);
	}
	}
}

