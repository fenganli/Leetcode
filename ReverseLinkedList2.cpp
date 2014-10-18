class Solution
{
	public:
	ListNode * reverseBetween(ListNode * head, int m, int n)
	{
		ListNode * newHead = new ListNode (0);
		newHead -> next = head;
		int index = 0;
		ListNode * p = newHead;
		while (index != m - 1)
		{
			p = p -> next;
			index++;
		}
		ListNode * tail = p;
		ListNode * subHead = p -> next;
		ListNode * subTail = p -> next;
		p = p -> next -> next;
		int count = m;
		while (count != n)
		{
			count ++;
			ListNode * swap = p -> next;
			p -> next = subHead;
			subHead = p;
			p = swap;
		}
		tail -> next = subHead;
		subTail -> next = p;
		return newHead -> next;
	}
};
