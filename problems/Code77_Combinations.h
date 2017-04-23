#pragma once
#include "../common/Common.h"

// 2017/03/13
// code url : https://leetcode.com/problems/combinations/#/description


namespace Code77
{
class Solution 
{
public:
	static void testMain()
	{
		Solution solution;
		int n = 4;
		int k = 2;
		vector<vector<int>> rets = solution.combine(4, 2);
		cout << LeetHelper::intVecInfos(rets) << "\n";
	}

public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> rets;
		vector<int> curVec;
		innerCombine(rets, curVec, n, 1, k);
		return rets;
	}

private:
	void innerCombine(vector<vector<int>>& rets, vector<int>& curVec,
		int n, int startNum, int cnt)
	{
		if (cnt == 0)
		{
			rets.push_back(curVec);
			return;
		}

		for (int i = startNum; i <= n; ++ i)
		{
			curVec.push_back(i);
			innerCombine(rets, curVec, n, i + 1, cnt - 1);
			curVec.pop_back();
		}
	}
};
}