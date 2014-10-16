class Solution
{
	public:
	TreeNode * sortedListToBST(ListNode * head)
	{
		if (head == NULL)
			return NULL;
		if (head -> next == NULL)
			return new TreeNode(head -> val);
		ListNode * p = head;
		int size = 0;
		while (p != NULL)
		{
			size++;
			p = p -> next;
		}
		int midIndex = size / 2;
		p = head;
		while (midIndex > 1)
		{
			p = p -> next;
			midIndex--;
		}
		TreeNode * root = new TreeNode(p -> next -> val);
		ListNode * rightHead = p -> next -> next;
		p -> next = NULL;
		root -> left = sortedListToBST(head);
		root -> right = sortedListToBST(rightHead);
		return root;
	}
};
