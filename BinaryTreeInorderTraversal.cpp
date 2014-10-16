class Solution
{
public:
	vector<int> inorderTraversal(TreeNode * root)
	{
		vector<int> returnVec;
		if (root == NULL)
			return returnVec;
		stack<TreeNode *> stack;
		stack.push(root);
		while (!stack.empty())
		{
			TreeNode * node = stack.top();
			stack.pop();
			if (node -> left != NULL || node -> right != NULL)
			{
				TreeNode * left = node -> left, * right = node -> right;
				node -> left = NULL;
				node -> right = NULL;
				if (right != NULL)
					stack.push(right);
				stack.push(node);
				if (left != NULL)
					stack.push(left);
			}
			else
				returnVec.push_back(node -> val);
		}
		return returnVec;
	}
};