// ss.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <queue>

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
	void buildTrees(int n, vector<vector<TreeNode*>>& trees)
	{
		trees[0].push_back(NULL);
		trees[1].push_back(new TreeNode(1));
		for (int i = 2; i <= n; i++)
		{
			for (int k = 0; k < i; k++)
			{
				//printf("i %d tree1-k %d tree2-j %d\n", i, k, i-1-k);
				pushTrees(trees[i], k + 1, trees[k], trees[i - 1 - k], k + 1);
			}
		}
	}

	void pushTrees(vector<TreeNode*>& ret, int rootVal, vector<TreeNode*>& tree1,
		vector<TreeNode*>& tree2, int offset2)
	{
		//printf("root %d tree1 %d tree2 %d of %d\n", rootVal, tree1.size(), tree2.size(), offset2);
		for (int i = 0; i < tree1.size(); ++i)
		{
			for (int j = 0; j < tree2.size(); ++j)
			{
				TreeNode* root = new TreeNode(rootVal);
				root->left = copyTree(tree1[i], 0);
				root->right = copyTree(tree2[j], offset2);
				ret.push_back(root);
			}
		}
	}

	TreeNode* copyTree(TreeNode* root, int offset)
	{
		if (!root) return NULL;
		TreeNode* newRoot = new TreeNode(root->val + offset);
		if (root->left) newRoot->left = copyTree(root->left, offset);
		if (root->right) newRoot->right = copyTree(root->right, offset);
		return newRoot;
	}

	void clacTreeCnts(int n, vector<int>& cnts)
	{
		//cnts.reserve(n + 1);
		cnts[0] = 1;
		cnts[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int k = 0; k <= (i - 1) / 2; ++k)
			{
				int j = i - 1 - k;
				if (j == k)
					cnts[i] += cnts[k] * cnts[j];
				else
					cnts[i] += 2 * cnts[k] * cnts[j];
			}
		}
	}

	vector<TreeNode*> generateTrees(int n)
	{
		if (n == 0) return vector<TreeNode*>();
		// clac treeCnts;
		vector<int> cnts(n+1, 0);
		clacTreeCnts(n, cnts);

		vector< vector<TreeNode*> > trees(n + 1, vector<TreeNode*>());

		for (int i = 0; i <= n; i++)
		{
			trees[i].reserve(cnts[i]);
		}

		buildTrees(n, trees);

		return trees[n];
	}
};

int main()
{
	Solution solution;
	solution.generateTrees(3);

	int i;
	cin >> i;
    return 0;
}

