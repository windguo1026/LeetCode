#pragma once
#include <iostream>
#include "StructDef.h"

using namespace std;

class TestHelper
{
public:
	TestHelper() {}
	~TestHelper() {}

public:
	template<typename Type>
	static void assertEqual(const char* info, Type bExp, Type bActual)
	{
		if (bExp == bActual)
		{
			cout << info << ": pass\n";
		}
		else
		{
			cout << info << ": failed. expect " << bExp
				<< " actual " << bActual << "\n";
		}
	}

	template<typename Type>
	static void assertVectorEqual(const char* info, const vector<Type>& vecExp,
		const vector<Type>& vecActual)
	{
		if (isVectorEqual(vecExp, vecActual))
		{
			cout << info << ": pass\n";
		}
		else
		{
			cout << info << ": failed\n";
		}
	}

	template<typename Type>
	static bool isVectorEqual(const vector<Type>& vecExp, const vector<Type>& vecActual)
	{
		if (vecExp.size() != vecActual.size())
		{
			return false;
		}

		for (int i = 0; i < vecExp.size(); ++i)
		{
			if (vecExp[i] != vecActual[i]) return false;
		}

		return true;
	}

};