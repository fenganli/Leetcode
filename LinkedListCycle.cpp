#include <iostream>
using namespace std;
struct ListNode
{
		int val;
		ListNode * next;
		ListNode (int x) : val(x), next(NULL) {}
};
class Solution
{
	public:
		bool hasCycle (ListNode * head)
		{
			if (head == NULL || head -> next == NULL)
					return false;
			ListNode * fast = head, * slow = head;
			while (fast != NULL && slow != NULL)
			{
				slow = slow -> next;
				fast = fast -> next;
				if (fast != NULL)
					fast = fast -> next;
				else
					break;
				if (fast == slow)
					break;
			}
			if (fast == NULL || slow == NULL)
				return false;
			else
				return true;
		}
};
