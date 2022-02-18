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

TEST(key_driver_test, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}