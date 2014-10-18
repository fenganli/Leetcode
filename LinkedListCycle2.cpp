#include <iostream>
#include <set>
using namespace std;
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next (NULL) {}
};
class Solution
{
	public:
	ListNode * detectCycle (ListNode * head)
	{
		if (head == NULL || head -> next == NULL)
			return NULL;
		ListNode * fastP = head, * slowP = head;
		while (fastP != NULL && slowP != NULL)
		{
			fastP = fastP -> next;
			if (fastP != NULL)
				fastP = fastP -> next;
			else
				break;
			slowP = slowP -> next;
			if (slowP == fastP)
				break;
		}
		if (fastP == NULL || slowP == NULL)
			return NULL;
		slowP = head;
		while (slowP != fastP)
		{
			slowP = slowP -> next;	
			fastP = fastP -> next;
		}
		return slowP;
		
	}
};
