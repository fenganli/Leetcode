class Solution
{
	int sum = 0;
	public:
	int sumNumbers(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		search(root, "");
		return sum;
	}
	void search(TreeNode *root, string s)
	{
		s += char(root -> val + '0');
		if (root -> left != NULL && root -> right != NULL)
		{
			search(root -> left, s);
			search(root -> right, s);
		}
		else if (root -> left != NULL)
			search(root -> left, s);
		else if (root -> right != NULL)
			search(root -> right, s);
		else
			sum += atoi(s.c_str());
		return;
	}
};
