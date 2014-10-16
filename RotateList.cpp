class Solution
{
public:
	ListNode * rotateRight (ListNode * head, int k)
	{
		if (head == NULL || k == 0)
			return head;
		int size = 0;
		ListNode * p = head;
		while (p != NULL)
		{
			size ++;
			p = p -> next;
		}
		int pos = size - 1 - (k - 1) % size;
		if (pos == 0)
		    return head;
		p = head;
		int index = 0;
		while (index != pos - 1)
		{
		    p = p -> next;
		    index++;
		}
		ListNode * newHead = p -> next;
		p -> next = NULL;
		p = newHead;
		while (p -> next != NULL)
		    p = p -> next;
		p -> next = head;
		return newHead;
	}
};