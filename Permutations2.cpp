class Solution
{
	public:
	vector<vector<int> > permuteUnique(vector<int> &num)
	{
		vector<vector<int> > retVec;
		sort(num.begin(), num.end());
		int size = num.size();
		if (size == 1)
		{
			vector<int> vec;
			vec.push_back(num[0]);
			retVec.push_back(vec);
			return retVec;
		}
		for (int i = 0; i < size; )
		{
			int j;
			for (j = i + 1; j < size; j++)
				if (num[j] != num[i])
					break;
			vector<int> inputVec = num;
			inputVec.erase(inputVec.begin() + i);
			vector<vector<int> > vec = permuteUnique(inputVec);
			int vecSize = vec.size();
			for (int k = 0; k < vecSize; k++)
			{
				vector<int> tempVec = vec[k];
				tempVec.push_back(num[i]);
				retVec.push_back(tempVec);
			}
			i = j;
		}
		return retVec;
	}
};
