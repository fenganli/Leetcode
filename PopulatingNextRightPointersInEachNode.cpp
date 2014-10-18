class Solution
{
	public:
		void connect(TreeLinkNode * root)
		{
			if (root == NULL)
				return;
			queue<TreeLinkNode *> queue;
			queue.push(root);
			queue.push(NULL);
			while (!queue.empty())
			{
				TreeLinkNode * node = queue.front();
				queue.pop();
				if (node != NULL)
				{
					node -> next = queue.front();
					if (node -> left != NULL)
						queue.push(node->left);
					if (node -> right != NULL)
						queue.push(node->right);
				}
				else
				{
					if (!queue.empty())
						queue.push(NULL);
				}
			}
			return;
		}
};
