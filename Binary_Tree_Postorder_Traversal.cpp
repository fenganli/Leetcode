/**
*Definition for binary tree
*/
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x):val(x), left(NULL), right(NULL) {}
};
class Solution
{
	public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> returnVec;
		if (root == NULL)
			return returnVec;
		vector<int>::iterator iter;
		if (root -> left != NULL)
		{
			vector<int> left_vec = postorderTraversal( root -> left);
			iter = left_vec.begin();
			while (iter != left_vec.end())
				returnVec.push_back(*(iter++));
		}
		if (root -> right != NULL)
		{
			vector<int> right_vec = postorderTraversal( root -> right);
			iter = right_vec.begin();
			while (iter != right_vec.end())
				returnVec.push_back(*(iter++));
		}
		returnVec.push_back(root->val):
		return returnVec;
	}
};
