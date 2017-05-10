#pragma once
#include "../common/Common.h"

// 2017/05/10
// https://leetcode.com/problems/unique-paths-ii/#/description

namespace Code63
{
class Solution
{
public:
	static void testMain()
	{

	}

public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		if (obstacleGrid.empty()) return 0;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		dp[m - 1][n] = 1;

		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
				}
			}
		}

		return dp[0][0];
	}
};
}