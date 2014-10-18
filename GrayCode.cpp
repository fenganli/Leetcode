class Solution
{
	public:
	vector<int> grayCode (int n)
	{
		vector<int> returnVec;
		int size = pow(2, n);
		string s(n, '0');
		returnVec.push_back(0);
		for (int i = 1; i < size; i++)
		{
			int index = getIndex(i);
			if (s[n - 1 -index] == '0')
				s[n - 1 - index] = '1';
			else
				s[n - 1 - index] = '0';
			char *p;
			returnVec.push_back(strtol(s.c_str(), &p, 2));
		}
		return returnVec;
	}
	int getIndex(int i )
	{
		int index = 1;
		while (i % (int)pow(2, index) == 0)
			index ++;
		return index - 1;
	}
};
