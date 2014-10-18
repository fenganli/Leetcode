class Solution
{
	public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{
		vector<vector<int> > returnVec;
		if (root == NULL)
			return returnVec; 
		if (sum == root -> val && root -> left == NULL && root -> right == NULL)
		{
			vector<int> vec;
			vec.push_back(sum);
			returnVec.push_back(vec);
			return returnVec;
		}
		for (int k = 0; k < 2; k++)
		{
			TreeNode * node;
			if (k == 0)
				node = root -> left;
			else
				node = root -> right;
			if (node != NULL)
			{
				vector<vector<int> > subVec = pathSum(node, sum - root -> val);
				int subSize = subVec.size();
				for (int i = 0; i < subSize; i++)
				{
					vector<int> vec;
					int subSubSize = subVec[i].size();
					vec.push_back(root -> val);
					for (int j = 0; j < subSubSize; j++)
						vec.push_back(subVec[i][j]);
					returnVec.push_back(vec);
				}
			}
		}
		return returnVec;
	}
};
