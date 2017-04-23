#pragma once
#include "../common/Common.h"

namespace Code477
{
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<vector<int>> numsArray =
		{
			{4,3},
			{1, 4, 7, 8, 10},
			{4, 14, 2},
			{0, 2}
		};

		for (int i = 0; i < numsArray.size(); ++i)
		{
			vector<int> nums = numsArray[i];
			cout << "nums: " << LeetHelper::intVecInfos(numsArray[i])
				<< " disances: " << so.totalHammingDistance(nums) << "\n";
		}
	}

public:
	int totalHammingDistance(vector<int>& nums)
	{
		int totalCnt = 0;
		while (true)
		{
			int set0Cnt = 0; // 最末1位为0的个数
			int set1Cnt = 0; // 最末1位为1的个数
			int zeroCnt = 0; // 经过多次计算之后，变成0的个数

			for (int i = 0; i < nums.size(); ++i)
			{
				((nums[i] & 0x1) == 0) ? (set0Cnt++) : (set1Cnt++);
				//printf("i %d nums[%d] %d set %d %d\n", i, i, nums[i], set0Cnt, set1Cnt);
				nums[i] = nums[i] >> 1;
				if (nums[i] == 0) zeroCnt++;
			}

			totalCnt += set0Cnt * set1Cnt;
			if (zeroCnt == nums.size()) break;
		}

		return totalCnt;
	}
};
}
