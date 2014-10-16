class Solution
{
	public:
	TreeNode * sortedArrayToBST(vector<int> &num)
	{
		int size = num.size();
		if (size == 0)
			return NULL;
		int * p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = num[i];
		int midIndex = size / 2;
		TreeNode * root = new TreeNode(p[midIndex]);
		TreeNode * left = buildBST(p, midIndex);
		TreeNode * right = buildBST(p + midIndex + 1, size - midIndex - 1);
		root -> left = left;
		root -> right = right;
		return root;
	}
	TreeNode * buildBST(int * p, int size)
	{
		if (size == 0)
			return NULL;
		int midIndex = size / 2;
		TreeNode * root = new TreeNode(p[midIndex]);
		TreeNode * left = buildBST(p, midIndex);
		TreeNode * right = buildBST(p + midIndex + 1, size - midIndex - 1);
		root -> left = left;
		root -> right = right;
		return root;
	}
};
