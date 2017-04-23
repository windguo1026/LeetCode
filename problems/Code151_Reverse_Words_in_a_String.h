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
	// 1.ȥ���ַ���ǰ���Լ�����֮�����Ŀո�
	// 2.˳��ѵ��ʷ�ת���絥�Ǻš�hello"��ת�ɡ�olleh"
	// 3.���յ�Ч��Ӧ���ǡ�  how are   you   " ��� "ouy era woh"
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
			// ��ǰһ�����ʵĿո�
			if (cur != 0) s[cur++] = ' ';
			int end = start;
			while (s[end] != ' ' && end < len) end++;
			// [start, end)Ϊһ������
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