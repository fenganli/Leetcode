class Solution
{
	vector<string> returnVec;
	char * p;
	public:
	vector<string> letterCombinations(string digits)
	{
		int size = digits.size();
		if (size == 0)
		{
			returnVec.push_back("");
			return returnVec;
		}
		p = new char[size+1];
		p[size] = '\0';
		search(0, digits);
		delete []p;
		return returnVec;
	}
	void search(int step, string digits)
	{
		if (step == digits.size())
			returnVec.push_back(string(p));
		int number = digits[step] - '0';
		if (number < 2 || number > 9)
			return;
		if (number <= 6)
		{
			for (int i = 0; i < 3; i++)
			{
				p[step] = (char)('a' + (number - 2) * 3 + i);
				search(step+1, digits);
			}
		}
		else if (number == 7)
		{
			for (int i = 0; i < 4; i++)
			{
				p[step] = (char)('p' + i);
				search(step+1, digits);
			}
		}
		else if (number == 8)
		{
			for (int i = 0; i < 3; i++)
			{
				p[step] = (char)('t' + i);
				search(step + 1, digits);
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				p[step] = (char)('w' + i);
				search(step+1, digits);
			}
		}
	}

};
