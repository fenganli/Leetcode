class Solution
{
	public:
	void nextPermutation(vector<int> &num)
	{
		int size = num.size();
		int i;
		for (i = size - 1; i >= 1; i--)
			if (num[i-1] < num[i])
				break;
		if (i == 0)
		{
			sort(num.begin(), num.end());
			return;
		}
		else
		{
			int mem = num[i];
			int index = i;
			for (int j = size - 1; j > i; j--)
				if (num[j] > num[i-1] && num[j] < mem)
				{
					index = j;
					mem = num[j];
				}
			num[index] = num[i-1];
			num[i-1] = mem;
			sort(num.begin() + i, num.end());
			return;
		}
	}
};
