class Solution
{
	public:
	vector<vector<int> > levelOrderBottom(TreeNode * root)
	{
		if (root == NULL)
		{
			vector<vector<int> > vec;
			return vec;
		}
		queue<TreeNode *> queue;
		queue.push(root);
		queue.push(NULL);
		vector<vector<int> > returnVec;
		vector<int> vec;
		while (!queue.empty())
		{
			TreeNode * node = queue.front();
			queue.pop();
			if (node == NULL)
			{
				returnVec.push_back(vec);
				if (!queue.empty())
					queue.push(NULL);
				vec.clear();
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
		vector<vector<int> > retVec;
		int size = returnVec.size();
		for (int i = size - 1; i >= 0; i--)
			retVec.push_back(returnVec[i]);
		return retVec;
	}
};
