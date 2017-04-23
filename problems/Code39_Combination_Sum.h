#pragma once
#include "../common/Common.h"

namespace Code39
{
class Solution {
public:
	static void testMain()
	{
		Solution solution;
		vector<int> nums = { 5, 1, 2, 3 };
		vector<vector<int>> rets = solution.combinationSum(nums, 8);
		cout << LeetHelper::intVecInfos(rets) << "\n";
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		if (target == 0) return vector<vector<int>>(1, vector<int>());

		sort(candidates.begin(), candidates.end());

		vector<vector<int>> rets;
		vector<int> curVec;

		combinSum(rets, candidates, curVec, target, 0);
		return rets;
	}

private:
	void combinSum(vector<vector<int>>& rets, vector<int>& candidates,
		vector<int>& curVec, int target, int beginIndex)
	{
		if (target == 0)
		{
			rets.push_back(curVec);
			return;
		}

		for (int i = beginIndex; i < candidates.size(); ++i)
		{
			if (candidates[i] > target) break;
			curVec.push_back(candidates[i]);
			combinSum(rets, candidates, curVec, target - candidates[i], i);
			curVec.pop_back();
		}
	}

	void calcDpCnts(vector<int>& candidates, int target, vector<int>& dp)
	{
		dp[0] = 1;
		for (int i = 0; i < candidates.size(); i++)
		{
			for (int j = candidates[i]; j <= target; j++)
			{
				dp[j] += dp[j - candidates[i]];
			}
		}
	}
};
}