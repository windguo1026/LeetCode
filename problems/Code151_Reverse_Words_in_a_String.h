#pragma once
#include "../common/Common.h"

// 03/25
// https://leetcode.com/problems/reverse-words-in-a-string/#/description

namespace Code151
{
class Solution
{
public:
	static void testMain()
	{
		vector<string> strs = 
		{
			"   ",
			"i am  here  ",
			"what  can i   do for   you    ",
			"",
			"fasdfasfasfe"
		};

		Solution so;
		for (string s : strs)
		{
			string oriStr = s;
			so.reverseWords(s);
			cout << "ori: \"" << oriStr << "\" reverse \"" << s << "\"\n";
		}
	}
public:
	void reverseWords(string &s) 
	{
		if (s.empty()) return;

		trimAndReverseWords(s);

		int len = s.size();
		reverseWords(s, 0, len - 1);
	}

private:
	// 1.去掉字符器前后以及单词之间多余的空格
	// 2.顺便把单词反转，如单记号”hello"反转成“olleh"
	// 3.最终的效果应该是“  how are   you   " 变成 "ouy era woh"
	void trimAndReverseWords(string& s)
	{
		if (s.empty()) return;
		int cur = 0;
		int start = 0;
		int len = s.size();
		while (start < len)
		{
			while (s[start] == ' ' && start < len) start ++;
			if (start == len)
			{
				break;
			}
			// 补前一个单词的空格
			if (cur != 0) s[cur++] = ' ';
			int end = start;
			while (s[end] != ' ' && end < len) end++;
			// [start, end)为一个单词
			reverseWords(s, start, end - 1);
			while (start < end) s[cur++] = s[start++];
		}
		s.resize(cur);
	}

	void reverseWords(string& s, int start, int end)
	{
		while (start < end) swapChar(s[start++], s[end--]);
	}

	void swapChar(char& x, char& y)
	{
		char t = x;
		x = y;
		y = t;
	}
};
}