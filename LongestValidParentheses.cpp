class Node
{
	public:
	int array;
	int index;
	Node (int x, int y) : array(x), index(y) {}
};
class Solution
{
	public:
	int longestValidParentheses(string s)
	{
		int size = s.size();
		if (size <= 1)
			return 0;
		stack<Node> stack;
		int maxLength = 0;
		for (int i = 0; i < size; i++)
		{
			 if (s[i] == '(')
				 stack.push(Node(0, i));
			 else
			 {
				 if (!stack.empty() && stack.top().array == 0)
				 {
					 stack.pop();
					 if (!stack.empty())
						 maxLength = max(maxLength, i - stack.top());
					 else
						 maxLength = max(maxLength, i + 1);
				 }
				 else
					 stack.push(Node(1, i));
			 }
		}
		return maxLength;
	}
};
