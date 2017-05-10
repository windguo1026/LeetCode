#include "../problems/Code63_Unique_Paths_2.h"
#include <gtest/gtest.h>

#define CODE63_UNIT_TEST 0

#if CODE63_UNIT_TEST

TEST(Code63_Unique_Paths_2, UnitTest)
{
	Code63::Solution so;

	vector<vector<int>> grid = 
	{
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};

	EXPECT_EQ(2, so.uniquePathsWithObstacles(grid));

	grid = { {1} };
	EXPECT_EQ(0, so.uniquePathsWithObstacles(grid));

	grid = { { 0 } };
	EXPECT_EQ(1, so.uniquePathsWithObstacles(grid));

	grid = { { 0, 0 }, {0, 1} };
	EXPECT_EQ(0, so.uniquePathsWithObstacles(grid));
}

#endif 