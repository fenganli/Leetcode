class Solution
{
	public:
	string simplifyPath(string path)
	{
		stack<string> stack;
		int size = path.size();
		if (size == 1)
			return path;
		string directory = "";
		for (int i = 1; i < size; i++)
		{
			if (path[i] != '/')
				directory += path[i];
			else
			{
				if (directory.compare(".") == 0)
					directory = "";
				else if (directory.compare("..") == 0)
				{
				    if (!stack.empty())
					    stack.pop();
					directory = "";
				}
				else
				{
				    if (directory.compare("") != 0)
					    stack.push(directory);
					directory = "";
				}
			}
		}
		
		if (directory.compare(".") == 0)
			directory = "";
		else if (directory.compare("..") == 0)
		{
			if (!stack.empty())
			{
				stack.pop();
				directory = "";
			}
		}
		else
		{
			if (directory.compare("") != 0)
				stack.push(directory);
			directory = "";
		}
		
		string returnPath = "";
		
		while (!stack.empty())
		{
			returnPath = "/" + stack.top() + returnPath;
			stack.pop();
		}
		
		if (returnPath[0] != '/')
		    returnPath = '/' + returnPath;
		    
		return returnPath;
	}
};
