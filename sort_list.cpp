/**
 * Definition for singly-linked list
 */
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(NULL){}
};
class Solution
{
public:
	ListNode *sortList(ListNode *head)
	{
		if (head == NULL || head -> next == NULL)
			return head;
		int midVal = head -> val;
		ListNode *lesHead = NULL;
		ListNode *bigHead = NULL;
		ListNode *lesIter = NULL;
		ListNode *bigIter = NULL;
		ListNode *iter = head -> next;
		while (iter != NULL)
		{
			if (iter -> val <= midVal)
				if (lesHead == NULL)
				{
					lesHead = iter;
					lesIter = iter;
				}
				else
				{
					lesIter -> next = iter;
					lesIter = iter;
				}
                else
                    if (bigHead == NULL)
                    {
                        bigHead = iter;
                        bigIter = iter;
                    }
                    else
                    {
                        lesIter -> next = iter;
                        lesIter = iter;
                    }
			iter ++;
		}
		lesIter -> next = NULL;
		bigIter -> next = NULL;
		lesHead = sortList(lesHead);
		bigHead = sortList(bigHead);
		if (lesHead != NULL)
		{
			iter = lesHead;
			while (iter -> next != NULL)
				iter++;
			iter -> next = head;
			head -> next = bigHead;
		}
		return lesHead;
	}
};


