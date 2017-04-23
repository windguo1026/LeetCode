#pragma once
#include "../common/Common.h"

#ifndef uint_32
typedef unsigned int uint32_t;
#endif // !uint_32


namespace StrHashTest
{
class Solution
{
public:
	static void testMain()
	{
		Solution so;
		vector<string> strs =
		{
			"hello word",
			"what",
			"fuck",
			"windguo",
			"windson",
			"wtd",
			"sbieuf",
			"whatTheFunk",
			"fasdf",
			"vs2017"
		};

		for (string str : strs)
		{
			uint32_t hash = so.bdkhash(str.c_str());
			cout << str << " " << hash << " " << hash%193 << "\n";
		}
	}

public:
	uint32_t bdkhash(const char* str)
	{
		uint32_t hash = 0;
		uint32_t seed = 31;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return hash;
	}
};
}