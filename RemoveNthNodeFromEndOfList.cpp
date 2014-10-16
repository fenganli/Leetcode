class Solution
{
public:
	ListNode * removeNthFromEnd(ListNode * head, int n)
	{
		ListNode * p = head;
		int count = 0;
	    while (p != NULL && count < n + 1)
	    {
	        p = p -> next;
	        count++;
	    }
	    if (p == NULL && count < n + 1)
	        return head -> next;
		ListNode * newP = head;
		while (p != NULL)
		{
			p = p -> next;
			newP = newP -> next;
		}
		newP -> next = newP -> next -> next;
		return head;
	}
};