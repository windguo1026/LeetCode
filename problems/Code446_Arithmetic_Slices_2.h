#pragma once
#include "../common/Common.h"

// 03/19
// url https://leetcode.com/problems/arithmetic-slices-ii-subsequence/#/description

namespace Code446
{
	class Solution
	{
	public:
		static void testMain()
		{
			Solution so;
			vector<vector<int>> numsArray =
			{
				{ 1,2,3,4,6,8,10,12 },
				{ 1,2,3,4 },
				{ 1, 1, 2, 5, 7 }
			};

			for (int i = 0; i < numsArray.size(); ++i)
			{
				vector<int>& A = numsArray[i];
				cout << " A: " << LeetHelper::intVecInfos(A)
					<< " cnt: " << so.numberOfArithmeticSlices(A) << "\n";
			}
		}

	public:
		int numberOfArithmeticSlices(vector<int>& A)
		{
			int nums = 0;
			int start = 0;
			while (start < A.size())
			{
				int cnt = getNextSlice(A, start);
				if (cnt != 0)
				{
					nums += (cnt - 2)*(cnt - 1) / 2;
				}

				start += (cnt == 0) ? 1 : (cnt - 1);
			}
			return nums;
		}

		int getNextSlice(vector<int>& A, int start)
		{
			int cnt = 0;
			for (int i = start + 2; i < A.size(); i++)
			{
				if (A[i] - A[i - 1] != A[i - 1] - A[i - 2]) break;
				cnt++;
			}
			return cnt == 0 ? 0 : (cnt + 2);
		}
	};
}