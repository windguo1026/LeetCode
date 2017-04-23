#pragma once
#include "../common/Common.h"

// 2017/03/19
// https://leetcode.com/problems/minimum-size-subarray-sum/#/description

namespace Code209
{
class Solution 
{
public:
	static void testMain()
	{
		Solution so;
		vector<vector<int>> numsArray = 
		{ 
			{ 2,3,1,2,4,3 },
			{ 1,3,4,8},
			{ 1,2,4,8,16 }
		};
		vector<int> sArray = { 7, 8,100};

		for (int i = 0; i < numsArray.size(); ++i)
		{
			vector<int>& nums = numsArray[i];
			int s = sArray[i];
			cout << "s: " << s << " nums: " << LeetHelper::intVecInfos(nums)
				<< " minLen: " << so.minSubArrayLen(s, nums) << "\n";
		}
	}
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		typedef unsigned int uint32_t;
		int curSum = 0;
		int first = 0;
		int last = 0;
		uint32_t minLen = (uint32_t)-1;

		while (last < nums.size())
		{
			curSum += nums[last++];
	
			while (curSum >= s)
			{
				int curLen = last - first;
				if (curLen < minLen)
				{
					minLen = curLen;
				}

				curSum -= nums[first++];
			}
		}

		return minLen == (-1) ? 0 : (int)minLen;
	}
};
}
