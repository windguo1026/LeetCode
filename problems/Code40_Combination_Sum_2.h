#pragma once
#include "../common/Common.h"

// 2017/03/13
// url https://leetcode.com/problems/combination-sum-ii/#/description

namespace Code40
{
class Solution
{
public:
	static void testMain()
	{
		Solution solution;
		vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
		int target = 8;
		vector<vector<int>> rets = solution.combinationSum2(candidates, target);
		cout << LeetHelper::intVecInfos(rets) << "\n";
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> rets;
		vector<int> curVec;
		innerCombi(rets, candidates, curVec, target, 0);
		return rets;
	}

private:
	void innerCombi(vector<vector<int>>& rets, vector<int>& candidates,
					vector<int>& curVec, int target, int startIndex)
	{
		if (target == 0)
		{
			rets.push_back(curVec);
			return;
		}

		for (int i = startIndex; i < candidates.size(); ++i)
		{
			if (candidates[i] > target) break;
			// key , why?
			if (i != startIndex && candidates[i] == candidates[i - 1]) continue;
			curVec.push_back(candidates[i]);
			innerCombi(rets, candidates, curVec, target - candidates[i], i + 1);
			curVec.pop_back();
		}
	}
};
}