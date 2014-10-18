class Solution 
{
	public:
	vector<vector<int> > generate (int numRows)
	{
		vector<vector<int> > returnVec;
		if (numRows == 0)
			return returnVec;
		for (int i = 0; i < numRows; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= i; j++)
				if (j == 0 || j == i)
					vec.push_back(1);
				else
					vec.push_back(returnVec[i-1][j] + returnVec[i-1][j-1]);
			returnVec.push_back(vec);
		}
		return returnVec;
	}
};
