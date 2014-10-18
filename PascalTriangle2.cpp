class Solution
{
	public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> vec;
		vector<int> newVec;
		vec.push_back(1);
		for (int i = 1;  i <= rowIndex; i++)
		{
			newVec.clear();
			for (int j = 0; j <= i; j++)
				if (j == 0 || j == i)
					newVec.push_back(1);
				else
					newVec.push_back(vec[j] + vec[j-1]);
			vec = newVec;
		}
		return vec;
	}
};
