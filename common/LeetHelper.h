#pragma once
#include <string>
#include <vector>
#include "StructDef.h"

using namespace std;

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif // !uint32_t


class LeetHelper
{
public:
	LeetHelper();
	~LeetHelper();

public:
	static uint32_t getCurTime();

public:
	// 生成数据相关
	static void genArray(vector<int>& nums, int cnt);
	static ListNode* genList(int cnt);
	static ListNode* genListFromVector(const vector<int>& nums);
	static ListNode* copyList(ListNode* head);
	static void releaseList(ListNode* head);

public:
	// 打印相关
	static string strVecInfos(vector<string>& strs);
	static string intVecInfos(vector<int>& vecs);
	static string intVecInfos(vector<vector<int>>& vecs);

	template<typename Type>
	static string vec2str(const vector<Type>& vecs)
	{
		ostringstream os;
		os << "[";
		for (int i = 0; i < vecs.size(); ++i)
		{
			os << vecs[i];
			if (i != vecs.size() - 1) os << ", ";
		}
		os << "]";
		return os.str();
	}

	template<typename Type>
	static string vec2str(vector<vector<Type>>& vecs, char sperChar = ',')
	{
		ostringstream os;
		os << "[";
		for (int i = 0; i < vecs.size(); ++i)
		{
			os << vec2str(vecs[i]);
			if (i != vecs.size() - 1) os << sperChar;
		}
		os << "]";
		return os.str();
	}

	static string list2str(ListNode* head);
};

