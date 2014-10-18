class Solution
{
	public:
	TreeNode * buildTree(vector<int> & inorder, vector<int> & postorder)
	{
		int * post = new int[inorder.size()];
		int * in = new int[inorder.size()];
		for (int i = 0; i < inorder.size(); i++)
		{
			post[i] = postorder[i];
			in[i] = inorder[i];
		}
		return buildTreeFromArray(in, post, inorder.size());
	}
	TreeNode * buildTreeFromArray(int * inorder, int * postorder, int size)
	{
		if (size == 0)
			return NULL;
		if (size == 1)
			return new TreeNode (inorder[0]);
		int idx;
		for (idx = 0; idx < size; idx++)
			if (inorder[idx] == postorder[size-1])
				break;
		TreeNode * left = buildTreeFromArray(inorder, postorder, idx);
		TreeNode * right = buildTreeFromArray(inorder + idx + 1, postorder + idx, size - idx - 1);
		TreeNode * root = new TreeNode (postorder[size-1]);
		root -> left = left;
		root -> right = right;
		return root;
	}
};
