#pragma once
#include "../common/Common.h"

// 2017/04/09
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/#/description

namespace Code378
{
class Solution
{
public:
	static void testMain()
	{
		vector<vector<int>> matrix = 
		{
			{1,  5, 9},
			{10, 11, 13},
			{12, 13, 15}
		};

		int k = 8;

		Solution so;
		int ret = so.kthSmallest(matrix, k);
		cout << "matrix \n"
			<< LeetHelper::vec2str(matrix, '\n') << "\n"
			<< "k " << k << " th element " << ret << "\n";
	}

public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		priority_queue<int> pq;

		for (int i = 0; i < matrix.size(); ++ i)
		{
			vector<int>& row = matrix[i];
			for (int j = 0; j < row.size(); ++j)
			{
				// 未够k个
				if (pq.size() < k)
				{
					pq.push(row[j]);
					continue;
				}

				// 后面的都会更大
				if (row[j] > pq.top())
				{
					break;
				}

				pq.pop();
				pq.push(row[j]);
			}
		}

		return pq.top();
	}
};
}