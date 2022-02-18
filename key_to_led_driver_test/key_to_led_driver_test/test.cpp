#include "gtest/gtest.h"

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

TEST_F(led_driver_test, Test_port_set) {
	EXPECT_EQ(0xFF, PORTA);
}