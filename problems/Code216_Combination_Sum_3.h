#pragma once
#include "../common/Common.h"

// 2017/03/14
// url https://leetcode.com/problems/combination-sum-iii/#/description

namespace Code216
{
class Solution
{
public:
	static void testMain()
	{
		Solution solution;
		vector<vector<int>> rets = solution.combinationSum3(3, 9);
		cout << "k = 3, n = 9 resuult = " << LeetHelper::intVecInfos(rets) << "\n";
		rets = solution.combinationSum3(3, 7);
		cout << "k = 3, n = 7 resuult = " << LeetHelper::intVecInfos(rets) << "\n";
		rets = solution.combinationSum3(5, 17);
		cout << "k = 5, n = 17 resuult = " << LeetHelper::intVecInfos(rets) << "\n";
		rets = solution.combinationSum3(4, 27);
		cout << "k = 4, n = 27 resuult = " << LeetHelper::intVecInfos(rets) << "\n";
	}

public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> rets;
		vector<int> curVec;
		innerComb(rets, curVec, n, k, 1);
		return rets;
	}

private:
	void innerComb(vector<vector<int>>& rets, vector<int>& curVec, int target,
				   int cnt, int startNum)
	{
		if (cnt == 0)
		{
			if (target == 0) rets.push_back(curVec);
			return;
		}

		for (int i = startNum; i <= 9; ++i)
		{
			if (target < i) break;
			if (9 - i + 1 < cnt) break;
			curVec.push_back(i);
			innerComb(rets, curVec, target - i, cnt - 1, i + 1);
			curVec.pop_back();
		}
	}
};
}