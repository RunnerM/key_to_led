#include "gtest/gtest.h"
#include "math.h"

extern "C"
{
#include "drivers/led_driver.h"
#include <avr/io.h>
}

class led_driver_test : public ::testing::Test
{
protected:
	void SetUp()
	{
		init_leds();
	}
	void TearDown() 
	{

	}
};

TEST_F(led_driver_test, Test_data_direction_set) {
	EXPECT_EQ(0xFF, DDRA);
}

TEST_F(led_driver_test, Test_port_set_to_initial) {
	EXPECT_EQ(0xFF, PORTA);
}
TEST_F(led_driver_test, Test_set_led_func) {
	for (int i = 0; i <= 8; i++) {
		set_led(i,1);
		uint8_t status = PINA & _BV(i);
		uint8_t res = pow(2,i);
		EXPECT_EQ(res, status);
	}
	
	
}