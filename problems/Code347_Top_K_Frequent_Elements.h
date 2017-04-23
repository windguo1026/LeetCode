#pragma once
#include "../common/Common.h"

// 2017/03/16
// url:https://leetcode.com/problems/top-k-frequent-elements/#/description

namespace Code347
{
class Solution
{
public:
	static void testMain()
	{
		Solution solution;
		int k = 2;
		vector<int> nums = { 1, 1, 2, 2, 3 };
		vector<int> rets = solution.topKFrequent(nums, k);
		cout << "nums: " << LeetHelper::intVecInfos(nums) << " k = " << k << " "
			 << "rets " << LeetHelper::intVecInfos(rets) << "\n";

		k = 3;
		nums = { 1, 2, 2, 2, 2, 6};
		rets = solution.topKFrequent(nums, k);
		cout << "nums: " << LeetHelper::intVecInfos(nums) << " k = " << k << " "
			 << "rets " << LeetHelper::intVecInfos(rets) << "\n";

		//TestHelper::assertVectorEqual("test1: ", )
	}

private:
	struct HeapNode
	{
		int m_val;
		int m_cnt;

		HeapNode()
			: m_val(0)
			, m_cnt(0)
		{

		}

		HeapNode(int val, int cnt)
			: m_val(val)
			, m_cnt(cnt)
		{

		}
	};

public:
	// 使用map + priority_queue实现
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		if (nums.empty()) return vector<int>();

		map<int, int> tmpMap;
		for (int i = 0; i < nums.size(); ++i)
		{
			tmpMap[nums[i]]++;
		}

		// 使用最小堆
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (auto it = tmpMap.begin(); it != tmpMap.end(); ++it)
		{
			if ( pq.size() < k || it->second > pq.top().first)
			{
				pq.push(pair<int, int>(it->second, it->first));
			}

			if (pq.size() > k) pq.pop();
		}

		vector<int> rets;
		rets.reserve(k);
		while (k-- > 0 && !pq.empty())
		{
			rets.emplace_back(pq.top().second);
			pq.pop();
		}

		return rets;
	}


	// 自己使用排序+最小堆的实现
	vector<int> topKFrequentMine(vector<int>& nums, int k)
	{
		if (nums.empty()) return vector<int>();
		sort(nums.begin(), nums.end());

		vector<HeapNode> heap;
		heap.reserve(k);
		buildMinHeap(heap, nums, k);

		vector<int> rets(k, 0);
		while (k-- > 0)
		{
			rets[k] = popMinHeap(heap);
		}
		return rets;
	}


private:
	void buildMinHeap(vector<HeapNode>& heap, vector<int>& nums, int k)
	{
		int cnt = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				cnt++;
				continue;
			}

			addHeapVal(heap, k, nums[i - 1], cnt);
			cnt = 1;
		}
		addHeapVal(heap, k, nums[nums.size() - 1], cnt);
	}

	void addHeapVal(vector<HeapNode>& heap, int maxHeapSize, int val, int cnt)
	{
		if (heap.size() == maxHeapSize)
		{
			if (cnt > heap[0].m_cnt)
			{
				heap[0].m_val = val;
				heap[0].m_cnt = cnt;
				shiftDownMinHeap(heap, 0, maxHeapSize);
			}
		}
		else
		{
			heap.emplace_back(val, cnt);
			if (heap.size() == maxHeapSize)
			{
				heapArray(heap);
			}
		}
	}

	void heapArray(vector<HeapNode>& heap)
	{
		int n = heap.size();
		for (int i = n / 2 - 1; i >= 0; --i)
		{
			shiftDownMinHeap(heap, i, n);
		}
	}

	void shiftDownMinHeap(vector<HeapNode>& heap, int i, int n)
	{
		// left: 2*i+1, right 2*i + 2
		HeapNode tmp = heap[i];
		int j = 2 * i + 1;

		while (j < n)
		{
			// 是否右子树更小
			if (j + 1 < n && heap[j + 1].m_cnt < heap[j].m_cnt) j++;

			if (tmp.m_cnt <= heap[j].m_cnt) break;

			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
		heap[i] = tmp;
	}

	int popMinHeap(vector<HeapNode>& heap)
	{
		int n = heap.size();
		HeapNode first = heap[0];
		heap[0] = heap[n - 1];
		heap.pop_back();
		if (n - 1 > 0)
		{
			shiftDownMinHeap(heap, 0, n - 1);
		}
		return first.m_val;
	}
};
}
