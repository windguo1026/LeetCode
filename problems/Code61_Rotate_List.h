#pragma once
#include "../common/Common.h"

// 0324
// https://leetcode.com/problems/rotate-list/#/description

namespace Code61
{
class Solution 
{
public:
	static void testMain()
	{
		Solution so;
		ListNode* head = LeetHelper::genList(5);

		srand(time(NULL));
		int k = 2;

		ListNode* oriList = LeetHelper::copyList(head);
		ListNode* newList = so.rotateRight(head, k);

		cout << "orgList: " << LeetHelper::list2str(oriList)
			<< " k " << k
			<< " rotateList: " << LeetHelper::list2str(newList) << "\n";

		LeetHelper::releaseList(oriList);
		LeetHelper::releaseList(newList);
	}

public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == NULL || k == 0) return head;
		int size = calcListCnt(head);
		k = k % size;
		if (k == 0) return head;

		ListNode* last = nthNode(head, size - 1);
		ListNode* newLast = nthNode(head, size - k - 1);
		ListNode* newHead = newLast->next;
		newLast->next = NULL;
		last->next = head;
		return newHead;
	}

private:
	int calcListCnt(ListNode* head)
	{
		int cnt = 0;
		while (head)
		{
			cnt ++;
			head = head->next;
		}
		return cnt;
	}

	// from 0 index
	ListNode* nthNode(ListNode* head, int n)
	{
		while (n -- > 0 && head) head = head->next;
		return head;
	}
};
}