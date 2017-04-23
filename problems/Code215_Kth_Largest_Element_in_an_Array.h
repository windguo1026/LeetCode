#pragma once
#include "../common/Common.h"

namespace Code215
{
class Solution 
{
public:
	static void testMain()
	{
		Solution solution;

		vector<int> oriNums;
		const int kArraySize = 10;
		LeetHelper::genArray(oriNums, kArraySize);

		//copy the array
		vector<int> numsResult = oriNums;
		sort(numsResult.begin(), numsResult.end());

		cout << "souce data " << LeetHelper::intVecInfos(oriNums) << "\n";
		cout << "sort data " << LeetHelper::intVecInfos(numsResult) << "\n";
		int size = numsResult.size();
		for (int k = 1; k <= size; ++ k)
		{
			stringstream ss;
			ss << "test " << k << ": (" << numsResult[size - k] << ")";

			vector<int> nums = oriNums;
			TestHelper::assertEqual(ss.str().c_str(), numsResult[size - k],
				solution.findKthLargest(nums, k));
		}
	}

public:
	int findKthLargest(vector<int>& nums, int k)
	{
		//return findKthLargestByQuickSort(nums, k);
		return findKthLargestByHeap(nums, k);
	}

private:
	// �ÿ��ŵ�˼���ҵ���K���Ԫ��
	int findKthLargestByQuickSort(vector<int>& nums, int k)
	{
		int targetIndex = nums.size() - k;
		int start = 0;
		int end = nums.size();
		while (start < end)
		{
			int m = partision(nums, start, end);
			if (m == targetIndex)
			{
				break;
			}
			else if (m < targetIndex)
			{
				start = m + 1;
			}
			else
			{
				end = m;
			}
		}
		return nums[targetIndex];
	}

	// [start, end)
	int partision(vector<int>& nums, int start, int end)
	{
		int randIdx = start + rand() % (end - start);
		swap(nums[start], nums[randIdx]);
		
		int x = nums[start];
		int i = start;
		int j = end - 1;

		while (i < j)
		{
			while (i < j && nums[j] > x) --j;
			if (i < j) nums[i++] = nums[j];

			while (i < j && nums[i] <= x) ++i;
			if (i < j) nums[j--] = nums[i];
		}
		nums[i] = x;
		return i;
	}

	void swap(int& x, int& y)
	{
		int t = x;
		x = y;
		y = t;
	}

private:
	void shiftDownMinHeap(vector<int>& heap, int i, int n)
	{
		// ������ֵ
		int x = heap[i];

		// ������ 2*i + 1, ������ 2*i+2
		int j = 2 * i + 1;
		while (j < n)
		{
			// �����ǲ�����������С
			if (j + 1 < n && heap[j + 1] < heap[j])
				++ j;

			if (heap[j] >= x) break;

			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
		heap[i] = x;
	}

	int findKthLargestByHeap(vector<int>& nums, int k)
	{
		// 1. ��n��Ԫ����ȡǰ��k��Ԫ�ع�������С��
		// 2, ���ں����(n-k)��Ԫ�أ����Ԫ��i���ڶ���Сֵ�����滻��Сֵ��Ȼ�������
		// 3. ����֮����ʵ�Ѷ����ǵ�k��Ԫ����
		vector<int> heap(nums.begin(), nums.begin()+k);

		// 1��
		int n = heap.size();
		for (int i = n/2 - 1; i >= 0; --i)
		{
			shiftDownMinHeap(heap, i, n);
		}

		// 2��
		for (int i = k; i < nums.size(); ++i)
		{
			if (nums[i] > heap[0])
			{
				heap[0] = nums[i];
				shiftDownMinHeap(heap, 0, n);
			}
		}

		return heap[0];
	}
};
}
