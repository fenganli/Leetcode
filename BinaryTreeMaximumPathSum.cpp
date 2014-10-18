class Solution
{
	public:
	int maxPathSum(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		int leftPath = maxPath(root -> left);
		int rightPath = maxPath(root -> right);
		int maxSum = max(leftPath, 0) + max(rightPath, 0) + root -> val;
		root -> val = maxSum;
		stack<TreeNode *> stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode * node = stack.top();
			stack.pop();
			if (node == NULL)
				continue;
			maxSum = max(maxSum, node -> val);
			stack.push(node -> left);
			stack.push(node -> right);
		}
		return maxSum;
	}
	int maxPath(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		int leftPath = maxPath(root -> left);
		int rightPath = maxPath(root -> right);
		int swap = root -> val;
		root -> val = max(leftPath, 0) + max(rightPath, 0) + root -> val;
		return swap + max(max(leftPath, rightPath), 0);
	}
};
