class Solution
{
	public:
	bool isValid(string s)
	{
		stack<char> stack;
		int size = s.size();
		for (int i = 0;  i < size; i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				stack.push(s[i]);
			else
			{
					if (!stack.empty())
					{
						char c = stack.top();
						stack.pop();
						if (s[i] == ')' && c == '(')
							continue;
						if (s[i] == '}' && c == '{')
							continue;
						if (s[i] == ']' && c == '[')
							continue;
						return false;
					}
					else
						return false;
			}
		}
		if (!stack.empty())
			return false;
		return true;
	}
};
