#pragma once
#include "../common/Common.h"

// 03/19
// url https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/#/description

namespace Code421
{
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<vector<int>> numsArray =
		{
			{ 3, 10, 5, 25, 2, 8 },
			{ 1,2,3,4 },
			{ 1, 1, 2, 5, 7 }
		};

		for (int i = 0; i < numsArray.size(); ++i)
		{
			vector<int> nums = numsArray[i];
			cout << " A: " << LeetHelper::intVecInfos(numsArray[i])
				<< " maxXOR: " << so.findMaximumXOR(nums) << "\n";
		}
	}
public:
	int findMaximumXOR(vector<int>& nums)
	{

	}
};
}