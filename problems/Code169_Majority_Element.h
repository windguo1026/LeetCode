#pragma once
#include "../common/Common.h"

// 03/22
// https://leetcode.com/problems/majority-element/#/solutions

namespace Code169
{

class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<vector<int>> numsArray =
		{
			{ 3, 3, 3, 3, 2, 8 },
			{ 1, 1, 1, 1, 1, 1, 2 },
			{ 22,3, 13421, 13421, 13421, 13421 },
			{ 1}
		};

		for (int i = 0; i < numsArray.size(); ++i)
		{
			vector<int> nums = numsArray[i];
			cout << "nums: " << LeetHelper::intVecInfos(numsArray[i])
				<< " major: " << so.majorityElement(nums) << "\n";
		}
	}
public:
	int majorityElement(vector<int>& nums)
	{
		return majorityElement3(nums);
	}

	// 方法1 使用unordermap直接计算
	int majorityElement1(vector<int>& nums)
	{
		unordered_map<int, int> cntMap;
		int size = nums.size();
		for (int n : nums)
		{
			cntMap[n] ++;
			if (cntMap[n] >= size / 2)
				return n;
		}
		return 0;
	}

	// 方法2 使用rand()
	int majorityElement2(vector<int>& nums)
	{
		srand(time(NULL));
		int size = nums.size();
		while (true)
		{
			int cnt = 0;
			int major = nums[rand() % size];
			for (int n : nums)
			{
				if (n == major)
				{
					cnt++;
					if (cnt > size / 2) return major;
				}
			}
		}

		return 0;
	}

	// 方法3 使用bitmask
	int majorityElement3(vector<int>& nums)
	{
		int major = 0;
		int size = nums.size();

		for (int i = 0; i < 32; ++i)
		{
			int mask = (1 << i);
			int cnt = 0;
			for (int n : nums)
			{
				if (!(n & mask)) continue;
				cnt++;
				if (cnt > size / 2)
				{
					major = major | mask;
					break;
				}
			}
		}

		return major;
	}
};
}