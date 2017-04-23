#pragma once
#include "../common/Common.h"

// url https://leetcode.com/problems/rotate-array/

namespace Code189
{
	class Solution
	{
	public:
		static void testMain()
		{
			Solution so;
			vector<vector<int>> numsArray =
			{
				{ 1 },
				{ 1, 2, 3, 4, 5, 6, 7 },
				{ 2, 2, 7 },
			};

			srand(time(NULL));
			for (int i = 0; i < numsArray.size(); ++i)
			{
				vector<int> nums = numsArray[i];
				int k = rand() % nums.size();
				so.rotate(nums, k);
				cout << "ori nums: " << LeetHelper::intVecInfos(numsArray[i])
					<< " k " << k
					<< " rets: " << LeetHelper::intVecInfos(nums) << "\n";
			}
		}
	public:
		void rotate(vector<int>& nums, int k)
		{
			rotate1(nums, k);
		}

		// 直接把数据移到它该到达的地方
		// 奇怪这个把%运算都改掉了，但运行效率竟然还不如方法2，有点奇怪
		void rotate1(vector<int>& nums, int k)
		{
			k = k % nums.size();
			if (nums.empty() || k == 0) return;
			int size = nums.size();

			for (int i = 0, cnt = 0; cnt < nums.size(); i++)
			{
				int tmp = nums[i];
				int start = (i + k) < size ? (i + k) : (i + k - size);
				int next = start;

				do
				{
					swap(tmp, nums[next]);
					next = (next + k) < size ? (next + k) : (next + k - size);
					cnt++;
				} while (next != start);
			}
		}

		// 使用两次交换
		void rotate2(vector<int>& nums, int k)
		{
			k = k % nums.size();
			if (nums.empty() || k == 0) return;

			reverse(nums, 0, nums.size() - 1);

			// k, n - k 
			reverse(nums, 0, k - 1);
			reverse(nums, k, nums.size() - 1);
		}

		void reverse(vector<int>& nums, int start, int end)
		{
			while (start < end)
			{
				swap(nums[start++], nums[end--]);
			}
		}

		void swap(int& x, int& y)
		{
			int a = x;
			x = y;
			y = a;
		}
};
}
