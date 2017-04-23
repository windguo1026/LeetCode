#pragma once
#include "../common/Common.h"

namespace Code76
{
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<string> sstrs = { "ADOBECODEBANC", "cdca", "abc", "abcdef"};
		vector<string> tstrs = { "ABC", "ca", "", "aab"};
		for (int i = 0; i < sstrs.size(); ++i)
		{
			string& s = sstrs[i];
			string& t = tstrs[i];
			cout << "s: \"" << s << "\" t: \"" << t 
				 << "\" minWindow: \"" << so.minWindow(s, t) << "\"\n";
		}
	}
public:

	string minWindow(string s, string t)
	{
		//异常判断 s, t是否为空
		if (t.empty())
		{
			return s.empty() ? "" : s.substr(0, 1);
		}

		int charMap[128] = { 0 };
		for (int i = 0; i < t.size(); ++i)
		{
			charMap[(unsigned char)t[i]] ++;
		}

		int tcnt = t.size();
		int first = 0; // 指向第一个字符的下标
		int last = 0;
		int minFirst = 0; // 最终选中的最小window的第一个字符下标
		unsigned int minWin = (unsigned int)(-1);

		while (last < s.size())
		{
			unsigned char c = (unsigned char)s[last];
			if (charMap[c] > 0) tcnt--;
			++ last;
			-- charMap[c];

			while (tcnt == 0)
			{
				unsigned int curWin = last - first;
				if (curWin < minWin)
				{
					minWin = curWin;
					minFirst = first;
				}

				// 移动first
				unsigned char f = (unsigned char)s[first];
				if (charMap[f] == 0) ++tcnt;
				++ charMap[f];
				++ first;
			}
		}
		return minWin == (unsigned int)(-1) ? "" : s.substr(minFirst, minWin);
	}
};
}
