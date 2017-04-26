#include <stdio.h>
#include <tchar.h>
#include <gtest/gtest.h>

int add(int a, int b)
{
	return a + b;
}

TEST(AddTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, add(1, 1));
	EXPECT_EQ(51, add(32, 18));
	EXPECT_EQ(50, add(32, 18));
}

int main(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}