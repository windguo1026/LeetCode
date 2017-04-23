#pragma once
#include "../common/Common.h"

// url https://leetcode.com/problems/majority-element-ii/#/description

namespace Code229
{
class Solution 
{
public:
	static void testMain()
	{
		Solution so;
		vector<vector<int>> numsArray =
		{
			{1},
			{1, 2},
			{2, 2},
			{3, 3, 3},
			{2, 2, 4, 4, 5,5,5,5,5},
			{2, 2, 2, 1, 1},
			{10, 10, 10, 10, 1}
		};

		for (int i = 0; i < numsArray.size(); ++i)
		{
			vector<int> nums = numsArray[i];
			vector<int> rets = so.majorityElement(nums);
			cout << "nums: " << LeetHelper::intVecInfos(numsArray[i])
				<< " rets: " << LeetHelper::intVecInfos(rets) << "\n";
		}
	}
public:
	vector<int> majorityElement(vector<int>& nums)
	{
		vector<int> rets;
		int n0;
		int n1;
		int cnt0 = 0;
		int cnt1 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (cnt0 != 0 && nums[i] == n0)
			{
				cnt0 ++;
				continue;
			}

			else if (cnt1 != 0 && nums[i] == n1)
			{
				cnt1++;
				continue;
			}

			if (cnt0 == 0)
			{
				n0 = nums[i];
				cnt0 = 1;
				continue;
			}

			if (cnt1 == 0)
			{
				n1 = nums[i];
				cnt1 = 1;
				continue;
			}

			-- cnt0;
			-- cnt1;
		}

		cnt0 = 0;
		cnt1 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == n0) cnt0++;
			else if (nums[i] == n1) cnt1++;
		}

		if (cnt0 > nums.size() / 3) rets.push_back(n0);
		if (cnt1 > nums.size() / 3) rets.push_back(n1);

		return rets;
	}
};
}