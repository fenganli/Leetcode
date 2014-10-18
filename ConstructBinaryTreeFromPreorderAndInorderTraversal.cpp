class Solution
{
	public:
	TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder)
	{
		int * pre = new int[preorder.size()];
		int * in = new int[inorder.size()];
		for (int i = 0; i < preorder.size(); i++)
		{
			pre[i] = preorder[i];
			in[i] = inorder[i];
		}
		return buildTreeFromArray(pre, in, preorder.size());
	}
	TreeNode * buildTreeFromArray(int * preorder, int * inorder, int size)
	{
		if (size == 0)
			return NULL;
		if (size == 1)
			return new TreeNode (preorder[0]);
		int idx;
		for (idx = 0; idx < size; idx++)
			if (inorder[idx] == preorder[0])
				break;
		TreeNode * left = buildTreeFromArray(preorder + 1, inorder, idx);
		TreeNode * right = buildTreeFromArray(preorder + idx + 1, inorder + idx + 1, size - idx - 1);
		TreeNode * root = new TreeNode (preorder[0]);
		root -> left = left;
		root -> right = right;
		return root;
	}
};
