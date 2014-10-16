class Solution
{
	public:
	ListNode * reverseKGroup(ListNode * head, int k)
	{
		if (head == NULL)
			return NULL;
		ListNode * p = head;
		ListNode *retHead = NULL, * retP = NULL;
		while (p != NULL)
		{
			ListNode * subTail = p;
			ListNode * subHead = p;
			p = p -> next;
			int i;
			for (i = 1; i < k; i++)
				if (p == NULL)
					break;
				else
				{
					ListNode * temp = p -> next;
					p -> next = subHead;
					subHead = p;
					p = temp;
				}
			subTail -> next = NULL;
			if (i < k)
			{
				ListNode * tempTail = subHead;
				ListNode * tempHead = subHead;
				ListNode * tempP = subHead -> next;
				while (tempP != NULL)
				{
					ListNode * _tempP = tempP -> next;
					tempP -> next = tempHead;
					tempHead = tempP;
					tempP = _tempP;
				}
				subHead = tempHead;
				subTail = tempTail;
				subTail -> next = NULL;
			}
			if (retHead == NULL)
			{
				retHead = subHead;
				retP = subTail;
			}
			else
			{
				retP -> next = subHead;
				retP = subTail;
			}
		}
		return retHead;
	}
};
