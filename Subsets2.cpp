class Solution
{
	vector<vector<int> > returnVec;
	public:
	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		if (S.size() == 0)
		{
			vector<vector<int> > vec;
			return vec;
		}
		sort(S.begin(), S.end());
		map<int, int> intCount;
		for (vector<int>::iterator iter = S.begin(); iter != S.end(); iter++)
			if (intCount.find(*iter) == intCount.end())
				intCount[*iter] = 1;
			else
				intCount[*iter] ++;
		int size = intCount.size();
		int *count = new int[size];
		for (int i = 0; i < size; i++)
			count[i] = 0;
		search(intCount, intCount.begin(), 0, size, count);
		return returnVec;
	}
	void search(map<int, int> &intCount, map<int, int>::iterator iter, int step, int size, int * count)
	{
		if (step == size)
		{
			vector<int> vec;
			int index = 0;
			for (map<int, int>::iterator iter = intCount.begin(); iter != intCount.end(); iter++)
			{
				for (int j = 0; j < count[index]; j++)
					vec.push_back(iter -> first);
				index++;
			}
			returnVec.push_back(vec);
			return;
		}
		for (int i = 0; i <= iter -> second; i++)
		{
			count[step] = i;
			search(intCount, ++iter, step + 1, size, count);
			iter--;
		}
		return;
	}
};
