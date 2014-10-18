class Solution
{
	public:
	void flatten (TreeNode * root)
	{
		if (root == NULL)
			return;
		flatten (root -> left);
		flatten (root -> right);
		if (root -> left == NULL)
			return;
		TreeNode * temp = root -> right;
		TreeNode * p = root -> left;
		while (p -> right != NULL)
			p = p -> right;
		root -> right = root -> left;
		root -> left = NULL;
		p -> right = temp;
		return;
	}
};
