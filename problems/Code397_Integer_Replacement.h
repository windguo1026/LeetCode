#pragma once
#include "../common/Common.h"
// 03/22
// https://leetcode.com/problems/integer-replacement/#/solutions

namespace Code397
{
	//2147483647
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<int> nums = {1, 8, 15, 2147483647};
		for (int n : nums)
		{
			printf("%d ret: %d\n", n, so.integerReplacement(n));
		}

		for (int n = 1334; n < 1434; n++)
		{
			int n1 = (n + 1) % 4;
			int n2 = (n + 1) & 3;
			printf("%d %d %d ret %d\n", n, n1, n2, n1-n2);
		}
	}

public:
	int integerReplacement(int n)
	{
		if (n == INT_MAX) return 32;
		int cnt = 0;
		while (n != 1)
		{
			cnt ++;
			if ((n & 1) == 0)
			{
				n = (n >> 1);
			}
			else if (n != 3 && (n+1) % 4 == 0)
			{
				++ n;
			}
			else
			{
				++n;
			}
			//cout << cnt << ":" << n << "\n";
		}
		return cnt;
	}
};
}

