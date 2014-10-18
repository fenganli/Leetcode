class Solution
{
	public:
	bool hasPathSum(TreeNode *root, int sum)
	{
		if (root == NULL)
			return false;
		int searchNum = sum - root -> val;
		if (searchNum == 0 && root -> left == NULL && root -> right == NULL)
			return true;
		if (root -> left != NULL && hasPathSum(root->left, searchNum))
			return true;
		if (root -> right != NULL && hasPathSum(root -> right, searchNum))
			return true;
		return false;
	}
};
