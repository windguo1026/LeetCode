#pragma once
#include "../common/Common.h"

// 03/17
// https://leetcode.com/problems/sort-characters-by-frequency/#/description

namespace Code451
{
class Solution 
{
public:
	static void testMain()
	{
		Solution so;

		string s = "cccaaa";
		cout << "before " << s << " sort: " << so.frequencySort(s) << "\n";

		s = "Aabb";
		cout << "before " << s << " sort: " << so.frequencySort(s) << "\n";

		s = "tree";
		cout << "before " << s << " sort: " << so.frequencySort(s) << "\n";

		s = "a";
		cout << "before " << s << " sort: " << so.frequencySort(s) << "\n";

		s = "abc";
		cout << "before " << s << " sort: " << so.frequencySort(s) << "\n";
	}

public:
	string frequencySort(string s)
	{
		if (s.empty()) return string();

		const int kArraySize = 128;
		int cnt[kArraySize] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			cnt[s[i]]++;
		}

		// ×î´ó¶Ñ
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < kArraySize; ++i)
		{
			if (cnt[i])
			{
				pq.push(pair<int, int>(cnt[i], i));
			}
		}

		string rets;
		rets.reserve(s.size());
		while (!pq.empty())
		{
			int n = pq.top().first;
			char c = (char)pq.top().second;
			for (int i = 0; i < n; ++i)
			{
				rets.push_back(c);
			}
			pq.pop();
		}

		return rets;
	}
};
}