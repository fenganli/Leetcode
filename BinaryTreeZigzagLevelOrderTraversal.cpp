class Solution
{
	public:
	vector<vector<int> > zigzagLevelOrder(TreeNode * root)
	{
		vector<vector<int> > returnVec;
		if (root == NULL)
			return returnVec;
		stack<TreeNode *> stack[2];
		stack[0].push(root);
		int index = 0;
		while (true)
		{
				int i = (index++) % 2;
				if (stack[i].empty())
					break;
				vector<int> vec;
				while (!stack[i].empty())
				{
					TreeNode * node = stack[i].top();
					stack[i].pop();
					vec.push_back(node -> val);
					if (i == 0)
					{
						if (node -> left != NULL)
							stack[1].push(node -> left);
						if (node -> right != NULL)
							stack[1].push(node -> right);
					}
					else
					{
						if (node -> right != NULL)
							stack[0].push(node -> right);
						if (node -> left != NULL)
							stack[0].push(node -> left);
					}
				}
				returnVec.push_back(vec);
		}
		return returnVec;
	}
};
