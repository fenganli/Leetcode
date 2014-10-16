class Solution
{
	public:
	int romanToInt(string s)
	{
		int size = s.size();
		int returnNum = 0;
		for (int i = 0; i < size; i++)
		{
			if (s[i] == 'M')
				returnNum += 1000;
			else if (s[i] == 'D')
				returnNum += 500;
			else if (s[i] == 'C')
			{
				if (i != size - 1 && s[i+1] == 'M')
				{
					returnNum += 900;
					i++;
				}
				else if (i != size - 1 && s[i+1] == 'D')
				{
					returnNum += 400;
					i++;
				}
				else
					returnNum += 100;
			}
			else if (s[i] == 'L')
				returnNum += 50;
			else if (s[i] == 'X')
			{
				if (i != size - 1 && s[i+1] == 'C')
				{
					returnNum += 90;
					i++;
				}
				else if (i != size - 1 && s[i+1] == 'L')
				{
					returnNum += 40;
					i++;
				}
				else 
					returnNum += 10;
			}
			else if (s[i] == 'V')
				returnNum += 5;
			else if (s[i] == 'I')
			{
				if (i != size - 1 && s[i+1] == 'X')
				{
					returnNum += 9;
					i++;
				}
				else if (i != size - 1 && s[i+1] == 'V')
				{
					returnNum += 4;
					i++;
				}
				else
					returnNum ++;
			}
		}
		return returnNum;
	}
};
