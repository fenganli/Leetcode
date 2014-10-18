class Solution
{
	public:
	vector<vector<int> > levelOrder(TreeNode * root)
	{
		vector<vector<int> > returnVec;
		if (root == 0)
			return returnVec;
		vector<int> vec;
		queue<TreeNode *> queue;
		queue.push(root);
		queue.push(NULL);
		while (!queue.empty())
		{
			TreeNode * node = queue.front();
			queue.pop();
			if (node == NULL)
			{
				returnVec.push_back(vec);
				vec.clear();
				if (!queue.empty())
					queue.push(NULL);
			}
			else
			{
				vec.push_back(node -> val);
				if (node -> left != NULL)
					queue.push(node -> left);
				if (node -> right != NULL)
					queue.push(node -> right);
			}
		}
		return returnVec;
	}
};
