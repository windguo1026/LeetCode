#include <gtest/gtest.h>
#include "../problems/Code62_Unique_Paths.h"

// 如果想跑Code62的单元测试，则设置成1
#define CODE62_UNIT_TEST 0

#if CODE62_UNIT_TEST

TEST(Code62_Unique_Paths, UnitTest)
{
	Code62::Solution so;
	EXPECT_EQ(1, so.uniquePaths(1, 1));
	EXPECT_EQ(so.uniquePathsDirect(2, 3), so.uniquePaths(2, 3));
	EXPECT_EQ(so.uniquePathsDirect(4, 11), so.uniquePaths(4, 11));
	EXPECT_EQ(635745396, so.uniquePaths(30, 11));
}

#endif // CODE62_UNIT_TEST
