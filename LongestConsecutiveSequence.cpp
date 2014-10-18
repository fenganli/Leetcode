class Solution
{
	public:
	int longestConsecutive(vector<int> & num)
	{
		unordered_set<int> set;
		int size = num.size();
		if (size == 0)
			return 0;
		for (int i = 0; i < size; i++)
			set.insert(num[i]);
		int maxSize = -1;
		while (!set.empty())
		{
			unordered_set<int>::iterator iter = set.begin();
			int num = *iter;
			int size = 1;
			set.erase(iter);
			for (int bigger = num + 1; ; bigger++)
			{
				if (set.find(bigger) != set.end())
				{
					size++;
					set.erase(bigger);
				}
				else
					break;
			}
			for (int lesser = num - 1; ; lesser--)
			{
				if (set.find(lesser) != set.end())
				{
					size++;
					set.erase(lesser);
				}
				else
					break;
			}
			maxSize = max(maxSize, size);
		}
		return maxSize;
	}
};
