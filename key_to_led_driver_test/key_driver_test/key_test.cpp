#include "gtest/gtest.h"


extern "C"
{
#include "drivers/key_driver.h"
#include <avr/io.h>
}

class key_driver_test : public ::testing::Test
{
protected:
	void SetUp()
	{
		init_keys();
	}
	void TearDown()
	{

	}
};

TEST_F(key_driver_test, test_data_direction_set) {
	EXPECT_EQ(0b00000000, DDRC & 0b00111111);
	EXPECT_EQ(0x00, DDRC & 0x3F);
}
TEST_F(key_driver_test, test_port_set_to_initial) {
	EXPECT_EQ(0b00111111, PORTC & 0b00111111);
	EXPECT_EQ(0x3F, PORTC & 0x3F);
}

TEST_F(key_driver_test, test_get_key_for_one) {
	PINA = 0b11101111;
	EXPECT_EQ(1,get_key(5));
}

TEST_F(key_driver_test, test_get_key_for_many) {
	PINA = 0b11111111;
	for (int i = 0; i <= 7;i++) {
		PINA &= ~(1 << i);
		EXPECT_EQ(1, get_key(i));
	}
}
