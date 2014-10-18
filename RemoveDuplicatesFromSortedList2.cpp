class Solution
{
public:
	ListNode * deleteDuplicates(ListNode * head)
	{
		if (head == NULL)
			return NULL;
		ListNode * retHead = NULL;
		ListNode * retP = NULL;
		ListNode * mem = head;
		ListNode * p = head -> next;
		bool single = true;
		while (p != NULL)
		{
			if (p -> val == mem -> val)
				single = false;
			else if (single)
			{
				if (retHead == NULL)
				{
					retHead = mem;
					retP = mem;
				}
				else
				{
					retP -> next = mem;
					retP = mem;
				}
				mem = p;
			}
			else
			{
				mem = p;
				single = true;
			}
			p = p -> next;
		}
	    if (single)
		{
			if (retHead == NULL)
			{
				retHead = mem;
				retP = mem;
			}
			else
			{
				retP -> next = mem;
				retP = mem;
			}
			mem = p;
		}
		if (retP != NULL)
		    retP -> next = NULL;
		return retHead;
	}
};