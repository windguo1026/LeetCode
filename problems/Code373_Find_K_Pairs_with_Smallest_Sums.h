#pragma once
#include "../common/Common.h"

// 2017/04/09
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/#/description

namespace Code373
{
class Solution
{
public:
	static void testMain()
	{
		vector<vector<int>> num1Array =
		{
			{ 1, 7, 11 },
			{ 1, 1, 2 },
			{ 1, 2 },
			{0, 0, 0, 0, 0}
		};

		vector<vector<int>> num2Array =
		{
			{ 2,  4, 6 },
			{ 1, 2, 3 },
			{ 3 },
			{ -3,22,35,56,76 }
		};

		vector<int> kArray =
		{
			3,
			2,
			3,
			22
		};

		Solution so;
		for (int i = 0; i < kArray.size(); ++i)
		{
			vector<int>& nums1 = num1Array[i];
			vector<int>& nums2 = num2Array[i];
			int k = kArray[i];

			vector<pair<int, int>> ret = so.kSmallestPairs(nums1, nums2, k);

			cout << "nums1 " << LeetHelper::vec2str(nums1) << "\n";
			cout << "nums2 " << LeetHelper::vec2str(nums2) << "\n";
			cout << "k " << k << "\n";
			cout << "rets cnt " << ret.size() << " {";

			for (int j = 0; j < ret.size(); ++ j)
			{
				pair<int, int>& cur = ret[j];
				cout << "[" << cur.first << ", " << cur.second << "]";
				if (j != ret.size() - 1) cout << ", ";
			}
			cout << "}\n\n";
		}
	}

public:
	struct PairCmp
	{
		bool operator ()(const pair<int, int>& lhs, const pair<int, int>& rhs) const
		{
			return lhs.first + lhs.second < rhs.first + rhs.second;
		}
	};

	// 使用priority_quque实现
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		// priority_quque默认就是最大堆，需要实现小于比较函数
		priority_queue<pair<int, int>, vector<pair<int, int>>, PairCmp> pq;

		for (int i = 0; i < nums1.size(); ++i)
		{
			for (int j = 0; j < nums2.size(); ++j)
			{
				pair<int, int> cur(nums1[i], nums2[j]);
				if (pq.size() < k)
				{
					pq.push(cur);
					continue;
				}

				if (!PairCmp()(cur, pq.top())) // !(cur < maxNode)
				{
					break;
				}

				pq.pop();
				pq.push(cur);
			}
		}

		vector<pair<int, int>> rets(pq.size(), pair<int, int>(0,0));
		int index = pq.size() - 1;
		while (!pq.empty())
		{
			rets[index--] = pq.top();
			pq.pop();
		}
		return rets;
	}

	// 使用multiSet实现
	vector<pair<int, int>> kSmallestPairs2(vector<int>& nums1, vector<int>& nums2, int k)
	{
		multiset <pair<int, int>, PairCmp> mset;

		for (int i = 0; i < nums1.size(); ++i)
		{
			for (int  j = 0; j < nums2.size(); ++j)
			{
				pair<int, int> cur(nums1[i], nums2[j]);
				if (mset.size() < k)
				{
					mset.insert(cur);
					continue;
				}

				auto last = mset.rbegin();
				if (!PairCmp()(cur, *last)) // !(cur < maxNode)
				{
					break;
				}

				mset.erase((++last).base());
				mset.insert(cur);
			}
		}

		vector<pair<int, int>> rets;
		rets.insert(rets.end(), mset.begin(), mset.end());
		return rets;
	}
};
}

