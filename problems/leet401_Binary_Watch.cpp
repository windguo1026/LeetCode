// ss.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include "LeetHelper.h"

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
	: val(x)
	, left(NULL)
	, right(NULL)
	{
	}
};

class Solution {
public:
	vector<string> readBinaryWatch(int num)
	{
		vector<string> rets;
		char buf[8];
		for (int h = 0; h < 12; h++)
		{
			for (int m = 0; m < 60; m++)
			{
				if (calcBits(h) + calcBits(m) == num)
				{
					sprintf(buf, "%d:%02d", h, m);
					rets.push_back(string(buf));
				}
			}
		}
		return rets;
	}
private:
	int calcBits(int n)
	{
		int cnt = 0;
		while (n)
		{
			cnt++;
			n = n & (n - 1);
		}
		return cnt;
	}
};

int main()
{
	Solution solution;
	vector<string> rets = solution.readBinaryWatch(1);

	cout << LeetHelper::strVecInfos(rets) << "\n";

	//int i;
	//cin >> i;

	system("pause");
	return 0;
}

