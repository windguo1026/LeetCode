#include <stdio.h>
#include <tchar.h>
#include <gtest/gtest.h>

int main(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	getchar();
	return ret;
}