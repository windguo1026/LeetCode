#include "LeetHelper.h"
#include <time.h>
#include <sstream>


LeetHelper::LeetHelper()
{
}


LeetHelper::~LeetHelper()
{
}

uint32_t LeetHelper::getCurTime()
{
	// todo [wind] need update
	return 0;//timeGetTime();
}

void LeetHelper::genArray(vector<int>& nums, int cnt)
{
	srand(time(NULL));
	nums.reserve(cnt);

	for (int i = 0; i < cnt; ++i)
	{
		nums.emplace_back(rand() % 65536);
	}
}

ListNode* LeetHelper::genList(int cnt)
{
	if (cnt == 0) return NULL;

	srand(time(NULL));
	ListNode gNode(0);
	ListNode* p = &gNode;
	while (cnt-- > 0)
	{
		p->next = new ListNode(rand() % 65536);
		p = p->next;
	}
	return gNode.next;
}

ListNode* LeetHelper::genListFromVector(const vector<int>& nums)
{
	ListNode gNode(0);
	ListNode* p = &gNode;
	for (int n: nums)
	{
		p->next = new ListNode(n);
		p = p->next;
	}
	return gNode.next;
}

ListNode* LeetHelper::copyList(ListNode* head)
{
	ListNode gNode(0);
	ListNode* p = &gNode;
	while (head)
	{
		p->next = new ListNode(head->val);
		head = head->next;
		p = p->next;
	}
	return gNode.next;
}

void LeetHelper::releaseList(ListNode* head)
{
	while (head)
	{
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}
}

string LeetHelper::strVecInfos(vector<string>& strs)
{
	ostringstream os;
	os << "[";
	for (int i = 0; i < strs.size(); ++i)
	{
		os << strs[i];
		if (i != strs.size()-1) os << ", ";
	}
	os << "]";
	return os.str();
}

string LeetHelper::intVecInfos(vector<int>& vecs)
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

string LeetHelper::intVecInfos(vector<vector<int>>& vecs)
{
	ostringstream os;
	os << "[";
	for (int i = 0; i < vecs.size(); ++i)
	{
		os << intVecInfos(vecs[i]);
		if (i != vecs.size() - 1) os << ", ";
	}
	os << "]";
	return os.str();
}

string LeetHelper::list2str(ListNode* head)
{
	ostringstream os;
	os << "[";
	while (head)
	{
		os << head->val;
		head = head->next;
		if (head) os << ", ";
	}
	os << "]";
	return os.str();
}
