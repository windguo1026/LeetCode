#pragma once
#include "../common/Common.h"

// 2017/05/10
// https://leetcode.com/problems/unique-paths/#/description

namespace Code62
{
class Solution
{
public:
	static void testMain()
	{

	}

public:
	// 直接了当的递归计算，只适用小数值，用于验证
	int uniquePathsDirect(int m, int n)
	{
		if (m == 1 && n == 1)
		{
			return 1;
		}

		int ret = 0;
		if (m > 1) ret += uniquePathsDirect(m - 1, n);
		if (n > 1) ret += uniquePathsDirect(m, n - 1);
		return ret;
	}

	int uniquePaths(int m, int n)
	{
		if (m < 1 || n < 1) return 0;

		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		dp[m - 1][n - 1] = 1;

		for (int i = m - 1; i >= 0; -- i)
		{
			for (int j = n - 1; j >= 0; -- j)
			{
				dp[i][j] += dp[i+1][j] + dp[i][j + 1];
			}
		}

		return dp[0][0];
	}
};
}