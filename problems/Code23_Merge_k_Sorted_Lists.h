#pragma once
#include "../common/Common.h"

// 03/25
// https://leetcode.com/problems/merge-k-sorted-lists/#/description


namespace Code23
{
	class Solution
	{
	public:
		static void testMain()
		{
			Solution so;
			vector<vector<int>> numsArray
			{
				{1, 4, 7, 10,100},
				{2, 5, 8, 200},
				{3, 6, 9, 12, 300},
				{1, 2, 20, 24, 34}
			};

			vector<ListNode*> numsList;
			numsList.reserve(numsArray.size());
			for (int i = 0; i < numsArray.size(); ++i)
			{
				ListNode* head = LeetHelper::genListFromVector(numsArray[i]);
				numsList.push_back(head);
				cout << "oriList" << (i + 1) << " " << LeetHelper::list2str(head) << "\n";
			}

			ListNode* mergeList = so.mergeKLists(numsList);
			cout << "merge " << LeetHelper::list2str(mergeList) << "\n";

			LeetHelper::releaseList(mergeList);
		}

	public:
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			if (lists.empty()) return NULL;
			return mergeKLists(lists, 0, lists.size()-1);
		}

	private:
		ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end)
		{
			if (start == end) return lists[start];

			int mid = start + (end - start) / 2;
			ListNode* lhs = mergeKLists(lists, start, mid);
			ListNode* rhs = mergeKLists(lists, mid + 1, end);
			return merge2List(lhs, rhs);
		}

		ListNode* merge2List(ListNode* lhs, ListNode* rhs)
		{
			ListNode gNode(0);
			ListNode* p = &gNode;
			while (lhs && rhs)
			{
				if (lhs->val <= rhs->val)
				{
					p->next = lhs;
					lhs = lhs->next;
				}
				else
				{
					p->next = rhs;
					rhs = rhs->next;
				}

				p = p->next;
			}

			p->next = lhs ? lhs : rhs;
			return gNode.next;
		}
};
}
