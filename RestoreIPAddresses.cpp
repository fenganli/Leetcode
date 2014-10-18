class Solution
{
	public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> returnVec;
		int size = s.size();
		if (size < 4 || size  > 12)
			return returnVec;
		for (int i = 1; i <= size - 3; i++)
			for (int j = i + 1; j <= size - 2; j++)
				for (int k = j + 1; k <= size - 1; k++)
				{
					if (s[0] == '0' && i > 1)
						continue;
					if (s[i] == '0' && j - i > 1)
						continue;
					if (s[j] == '0' && k - j > 1)
						continue;
					if (s[k] == '0' && size - k > 1)
						continue;
					int num1 = atoi(s.substr(0, i).c_str());
					int num2 = atoi(s.substr(i, j - i).c_str());
					int num3 = atoi(s.substr(j, k - j).c_str());
					int num4 = atoi(s.substr(k, size - k).c_str());
					bool b1 = (num1 >= 0 && num1 <= 255);
					bool b2 = (num2 >= 0 && num2 <= 255);
					bool b3 = (num3 >= 0 && num3 <= 255);
					bool b4 = (num4 >= 0 && num4 <= 255);
					if (b1 && b2 && b3 && b4)
					{
						string temp = s;
						temp.insert(i, 1, '.');
						temp.insert(j+1, 1, '.');
						temp.insert(k+2, 1, '.');
						returnVec.push_back(temp);
					}
				}
		return returnVec;
	}
};
