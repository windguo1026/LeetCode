#pragma once
#include "../common/Common.h"

// 03/19
// url https://leetcode.com/problems/maximum-product-of-word-lengths/#/description

namespace Code318
{
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<string> strs;

		strs = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
		cout << " words: " << LeetHelper::vec2str(strs) << " cnt: " << so.maxProduct(strs) << "\n";
	
		strs = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
		cout << " words: " << LeetHelper::vec2str(strs) << " cnt: " << so.maxProduct(strs) << "\n";

		strs = { "a", "aa", "aaa", "aaaa" };
		cout << " words: " << LeetHelper::vec2str(strs) << " cnt: " << so.maxProduct(strs) << "\n";
	}

public:
	// 1. ��words���������򣬳�����ǰ��
	// 2. ��һ��32λ��bit������ÿ��������ĸ���ֵĴ���
	// 3. ����mitmask��list
	int maxProduct(vector<string>& words)
	{
		sort(words.begin(), words.end(), [](const string& lhs, const string& rhs)
		{
			return lhs.size() > rhs.size();
		});

		typedef unsigned int uint32_t;
		vector<uint32_t> bitMask(words.size(), 0);

		for (int i = 0; i < words.size(); ++i)
		{
			for (unsigned char c : words[i])
				bitMask[i] |= (1 << (c - 'a'));
		}

		int maxPro = 0;
		for (int i = 0; i < bitMask.size(); ++i)
		{
			// ��Ϊ i ����� ���ʳ��ȶ�С��i�ģ����Ժ��涼�����ٱ���
			if (words[i].size() * words[i].size() < maxPro) break;
			for (int j = i + 1; j < bitMask.size(); ++j)
			{
				if (bitMask[i] & bitMask[j]) continue;
				int pro = words[i].size() * words[j].size();
				if (pro > maxPro)
				{
					maxPro = pro;
					break;
				}
			}
		}

		return maxPro;
	}

	// �����򵥵�(n2���㷨������
	int maxProduct2(vector<string>& words)
	{
		int maxPro = 0;
		int size = words.size();
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				int product = 0;
				if (!isWordhasCommonChar(words[i], words[j]))
				{
					product = words[i].size() * words[j].size();
					maxPro = max(maxPro, product);
				}
			}
		}
		return maxPro;
	}

	bool isWordhasCommonChar(const string& lhs, const string& rhs)
	{
		int m[128] = { 0 };
		for (unsigned char c : lhs) m[c] = 1;

		for (unsigned char c : rhs)
		{
			if (m[c]) return true;
		}

		return false;
	}
};
}
