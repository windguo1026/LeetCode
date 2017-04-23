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

void pushChar(string& s, char val)
{
	s.push_back(val);
}

void pushint(string& s, int val)
{
	char* p = (char*)&val;
	s.push_back(p[0]);
	s.push_back(p[1]);
	s.push_back(p[2]);
	s.push_back(p[3]);
}

char popchar(string& s, int& curPos)
{
	return s[curPos++];
}

int popint(string& s, int& curPos)
{
	int ret = 0;
	char* p = (char*)&ret;
	p[0] = s[curPos];
	p[1] = s[curPos+1];
	p[2] = s[curPos+2];
	p[3] = s[curPos+3];
	curPos += 4;
	return ret;
}

void innerSerialize(TreeNode* root, string& ss)
{
	if (!root)
	{
		pushChar(ss, 0);
		return;
	}

	pushChar(ss, 1);
	pushint(ss, root->val);
	innerSerialize(root->left, ss);
	innerSerialize(root->right, ss);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
	string ss;
	if (!root) return ss;

	queue<TreeNode*> qe;
	qe.push(root);

	while (!qe.empty())
	{
		TreeNode* cur = qe.front();
		qe.pop();

		if (!cur)
		{
			pushChar(ss, 0);
			continue;
		}

		pushChar(ss, 1);
		pushint(ss, cur->val);

		if (cur->left || cur->right)
		{
			qe.push(cur->left);
			qe.push(cur->right);
		}
	}

	return ss;
}

TreeNode* createTree(string& str, int& curPos)
{
	if (curPos >= str.size()) return NULL;

	char type = popchar(str, curPos);
	if (type == 0)
	{
		return NULL;
	}

	int curVal = popint(str, curPos);
	TreeNode* root = new TreeNode(curVal);
	root->left = createTree(str, curPos);
	root->right = createTree(str, curPos);
	return root;
}

TreeNode* getNode(string& data, int& curPos)
{
	char type = popchar(data, curPos);
	if (type == 0) return NULL;
	int val = popint(data, curPos);
	return new TreeNode(val);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
	if (data.empty()) return NULL;
	int curPos = 0;
	TreeNode* root = getNode(data, curPos);
	queue<TreeNode*> qe;
	qe.push(root);

	while (curPos < data.size())
	{
		TreeNode* cur = qe.front();
		qe.pop();

		cur->left = getNode(data, curPos);
		cur->right = getNode(data, curPos);
		//printf("cur %d left %d, right %d\n", cur->val,
		//	cur->left ? cur->left->val : 0,
		//	cur->right ? cur->right->val : 0);
		if (cur->left) qe.push(cur->left);
		if (cur->right) qe.push(cur->right);
	}

	return root;
}


uint32_t reverseBits(uint32_t n)
{
	int ret = 0;
	int k = 32;
	while (k--)
	{
		ret = (ret << 1) + (n & 1);
		n = n >> 1;
	}
	return ret;
}

int main()
{
	unsigned int n = 1;
	unsigned int n2 = reverseBits(n);
	printf("%d %u", n, n2);
	//int a = 0x11223344;
	//char* p = (char*)&a;
	//printf("%x %x %x %x", p[0], p[1], p[2], p[3]);
	//TreeNode* root = new TreeNode(9);
	//root->left = new TreeNode(8);
	//root->right = new TreeNode(13);
	//root->left->left = new TreeNode(7);
	//root->right->left = new TreeNode(10);
	//root->right->right = new TreeNode(14);
	//root->right->right->right = new TreeNode(15);

	//string str = serialize(root);

	//TreeNode* newRoot = deserialize(str);

	int i;
	cin >> i;
    return 0;
}

