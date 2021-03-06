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

TEST_F(led_driver_test, test_data_direction_set) {
	EXPECT_EQ(0xFF, DDRA);
}

TEST_F(led_driver_test, test_port_set_to_initial) {
	EXPECT_EQ(0xFF, PORTA);
}

TEST_F(led_driver_test, Test_set_led_func_for_one) {
	set_led(1,1);
	uint8_t status = PINA & _BV(PINA1);
	EXPECT_EQ(status,0);
}
