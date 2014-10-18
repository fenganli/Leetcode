class Solution
{
public:
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode*> vec;
		int * array = new int[n];
		for (int i = 0; i < n; i++)
			array[i] = i + 1;
		for (int i = 0; i < n; i++)
		{
			vector<TreeNode*> left = getTrees(array, i);
			vector<TreeNode*> right = getTrees(array + i + 1, n- i - 1);
			int leftSize = left.size();
			int rightSize = right.size();
			for (int k = 0; k < leftSize; k++)
				for (int j = 0; j < rightSize; j++)
				{
					TreeNode * root = new TreeNode(array[i]);
					root -> left = left[k];
					root -> right = right[j];
					vec.push_back(root);
				}	
		}
		if (vec.size() != 0)
		    return vec;
		else
		{
		    vec.push_back(NULL);
		    return vec;
		}
	}
	vector<TreeNode *> getTrees(int * array, int size)
	{
		if (size == 0)
		{
			vector<TreeNode *> vec;
			vec.push_back(NULL);
			return vec;
		}
		vector<TreeNode *> vec;
		for (int i = 0; i < size; i++)
		{
			vector<TreeNode*> left = getTrees(array, i);
			vector<TreeNode*> right = getTrees(array + i + 1, size - i -1);
			int leftSize = left.size();
			int rightSize = right.size();
			for (int k = 0; k < leftSize; k++)
				for (int j = 0; j < rightSize; j++)
				{
					TreeNode * root = new TreeNode (array[i]);
					root -> left = left[k];
					root -> right = right[j];
					vec.push_back(root);
				}
		}
		return vec;
	}
};
