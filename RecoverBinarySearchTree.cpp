class Solution
{
	TreeNode * nodeA1 = NULL, *nodeB1 = NULL, *nodeA2 = NULL, *nodeB2 = NULL;
	public:
	void recoverTree(TreeNode * root)
	{
		if (root == NULL)
			return;
		inorderTravel(root);
		if (nodeB1 != NULL)
			if (nodeB2 == NULL)
			{
				int swap = nodeB1 -> val;
				nodeB1 -> val = nodeA1 -> val;
				nodeA1 -> val = swap;
			}
			else
			{
				int swap = nodeB2 -> val;
				nodeB2 -> val = nodeA1 -> val;
				nodeA1 -> val = swap;
			}
		return;
	}
	void inorderTravel(TreeNode * root)
	{
		if (root == NULL)
			return;
		inorderTravel(root -> left);
		if (nodeA1 == NULL)
			nodeA1 = root;
		else if (nodeB1 == NULL)
		{
			if (root -> val < nodeA1 -> val)
			{
				nodeB1 = root;
				nodeA2 = root;
			}
			else
				nodeA1 = root;
		}
		else if (nodeB2 == NULL)
			if (root -> val < nodeA2 -> val)
				nodeB2 = root;
			else
				nodeA2 = root;
		inorderTravel(root -> right);
	}
};
