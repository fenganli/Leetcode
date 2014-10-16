class Solution
{
	public:
	string getPermutation(int n, int k)
	{
		k--;
		vector<bool> vec;
		for (int i = 0; i <= n; i++)
			vec.push_back(true);
		string result = "";
		for (int i = n; i >= 1; i--)
		{
			if (i == 1)
			{
				for (int j = 1; j <= n; j++)
					if (vec[j])
						result += char ('0' + j);
			}
			else
			{
				int num = k / get(i-1);
				k = k - num * get(i-1);
				int count = 0;
				for (int j = 1; j <= n; j++)
					if (vec[j])
						if (count != num)
							count++;
						else
						{
							result += char ('0' + j);
							vec[j] = false;
							break;
						}
			}
		}
		return result;
	}
	int get(int i)
	{
		if (i == 1)
			return 1;
		else
			return i * get(i-1);
	}
};
