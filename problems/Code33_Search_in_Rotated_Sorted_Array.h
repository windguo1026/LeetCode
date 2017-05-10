#pragma once
#include "../common/Common.h"

// 2017/05/10
// https://leetcode.com/problems/search-in-rotated-sorted-array/#/description

namespace Code33
{
class Solution
{
public:
	static void testMain()
	{

	}
public:
	int search(vector<int>& nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}

		int start = 0;
		int end = (int)nums.size() - 1;
		if (nums[start] < nums[end])
		{
			return binarySearch(nums, start, end, target);
		}
		else
		{
			return specialSearch(nums, start, end, target);
		}
	}

private:
	int specialSearch(vector<int>& nums, int start, int end, int target)
	{
		if (start > end)
		{
			return -1;
		}

		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}

		if (nums[start] <= nums[mid])
		{
			if (target >= nums[start] && target < nums[mid])
			{
				return binarySearch(nums, start, mid - 1, target);
			}
			else
			{
				return specialSearch(nums, mid + 1, end, target);
			}
		}
		else
		{
			if (target > nums[mid] && target <= nums[end])
			{
				return binarySearch(nums, mid + 1, end, target);
			}
			else
			{
				return specialSearch(nums, start, mid - 1, target);
			}
		}
	}

	int binarySearch(vector<int>& nums, int start, int end, int target)
	{
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] < target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return -1;
	}
};
}