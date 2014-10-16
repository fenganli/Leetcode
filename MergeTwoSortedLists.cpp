class Solution
{
	public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode * l2)
	{
		ListNode * p1 = l1, * p2 = l2;
		ListNode * root = NULL, * p = NULL;
		while (p1 != NULL || p2 != NULL)
		{
			if (p1 != NULL && p2 != NULL)
			{
				if (p1 -> val < p2 -> val)
					if (root == NULL)
					{
						root = p1;
						p = p1;
						p1 = p1 -> next;
					}
					else
					{
						p -> next = p1;
						p = p1;
						p1 = p1 -> next;
					}
				else
					if (root == NULL)
					{
						root = p2;
						p = p2;
						p2 = p2 -> next;
					}
					else
					{
						p -> next = p2;
						p = p2;
						p2 = p2 -> next;
					}
			}
			else if (p1 != NULL)
				if (root == NULL)
				{
					root = p1;
					p = p1;
					p1 = p1 -> next;
				}
				else
				{
					p -> next = p1;
					p = p1;
					p1 = p1 -> next;
				}
			else
				if (root == NULL)
				{
					root = p2;
					p = p2;
					p2 = p2 -> next;
				}
				else
				{
					p -> next = p2;
					p = p2;
					p2 = p2 -> next;
				}
		}
		return root;
	}
};
