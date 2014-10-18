class Solution
{
	public:
	int numDecodings(string s)
	{
		int size = s.size();
		if (size == 0)
			return 0;
		int *p;
		p = new int[size];
		if (s[0] != '0')
			p[0] = 1;
		else
			p[0] = 0;
		for (int i = 1; i < size; i++)
		{
				int sum  = 0;
				if (s[i] != '0')
				{
					sum = p[i-1];
					int index = (s[i-1] - '0') * 10 + s[i] - '0';
					if (index >= 10 && index <= 26)
						if (i == 1)
							sum += 1;
						else
							sum += p[i-2];
				}
				else
				{
					if (s[i-1] - '0' == 1 || s[i-1] - '0' == 2)
						if (i == 1)
							sum = 1;
						else
							sum = p[i-2];
					else
						sum = 0;
				}
				p[i] = sum;
		}
		int returnNum = p[size-1];
		delete []p;
		return returnNum;
	}
};
