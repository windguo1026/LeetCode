#pragma once
#include "../common/Common.h"

// 03/26
// url https://leetcode.com/problems/rotate-function/#/description

namespace Code396
{
class Solution
{
public:
	static void testMain()
	{
		vector<vector<int>> numsArray = 
		{
			{4, 3, 2, 6},
			{1,2,3,4,5,6,7,8,9,10 },
			{2, 7, 32, 21, 23, 34, 423, 234}
		};

		Solution so;
		for (vector<int> nums : numsArray)
		{
			int maxVal = so.maxRotateFunction(nums);
			cout << "nums: " << LeetHelper::vec2str(nums)
				<< " max: " << maxVal << "\n";
		}
	}
public:
	int calc(vector<int>& A, int k)
	{
		int x = 0;
		int sum = 0;
		for (int i = A.size() - k; i < A.size(); i++)
		{
			sum += x * A[i];
			x ++;
		}

		for (int i = 0; i < (A.size() - k); ++i)
		{
			sum += x * A[i];
			x ++;
		}
		return sum;
	}

	int maxRotateFunction(vector<int>& A)
	{
		// calc the base sum
		int n = A.size();
		int sum = 0;
		int lastVal = 0;

		for (int i = 0; i < n; ++ i)
		{
			sum += A[i];
			lastVal += i * A[i];
		}

		int maxVal = lastVal;
		for (int k = 1; k < n; ++k)
		{
			int index = n - k;
			int curVal = lastVal + sum - n * A[index];

			maxVal = max(curVal, maxVal);
			//printf("k %d index %d cur %d last %d max %d expet %d\n",
			//	k, index, curVal, lastVal, maxVal, calc(A, k));
			lastVal = curVal;
		}

		return maxVal;
	}
};
}
