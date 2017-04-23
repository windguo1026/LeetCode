#pragma once
#include "../common/Common.h"

namespace Code380
{
class RandomizedSet
{
public:
	static void testMain()
	{
		RandomizedSet set;
		assertEqual("set.insert(1)", true, set.insert(1));
		assertEqual("set.insert(1)", false, set.insert(1));
		assertEqual("set.insert(2)", true, set.insert(2));
		assertEqual("set.insert(3)", true, set.insert(3));
		assertEqual("set.remove(2)", true, set.remove(2));
		assertEqual("set.remove(2)", false, set.remove(2));
		assertEqual("set.insert(4)", true, set.insert(4));
		assertEqual("set.insert(5)", true, set.insert(5));
		assertEqual("set.remove(6)", false, set.remove(6));
		assertEqual("set.remove(4)", true, set.remove(4));
		assertEqual("set.insert(6)", true, set.insert(6));
		cout << "rand1 " << set.getRandom() << "\n";
		cout << "rand2 " << set.getRandom() << "\n";
		cout << "rand3 " << set.getRandom() << "\n";
	}

	template<typename Type>
	static void assertEqual(char* info, Type bExp, Type bActual)
	{
		if (bExp == bActual)
		{
			cout << info << ": pass\n";
		}
		else
		{
			cout << info << ": failed. expect "<< bExp
				 << " actual " << bActual << "\n";
		}
	}

public:
	/** Initialize your data structure here. */
	RandomizedSet()
	{

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		if (m_valMap.find(val) != m_valMap.end())
		{
			return false;
		}

		m_valVec.emplace_back(val);
		m_valMap[val] = m_valVec.size() - 1; // val -> vecIndex;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		unordered_map<int, int>::iterator it = m_valMap.find(val);
		if ( it == m_valMap.end())
		{
			return false;
		}

		// 主要思想，把数组最后一个值，移到要删除的那个位置上
		// 然后更新“最后一个值”对应的下标
		int removeIndex = it->second;
		int lastVal = m_valVec.back();
		m_valVec[removeIndex] = lastVal;
		m_valMap[lastVal] = removeIndex;
		m_valVec.pop_back();

		m_valMap.erase(it);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		return m_valVec[rand() % m_valVec.size()];
	}

private:
	unordered_map<int, int> m_valMap;
	vector<int> m_valVec;
};

}
