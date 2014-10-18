class Solution
{
	vector<vector<bool> > matrix;
	public:
	vector<vector<string> > partition(string s)
	{
		vector<vector<string> > returnVec;
		int size = s.size();
		if (size == 0)
			return returnVec;
		for (int i = 0;i < size; i++)
		{
			vector<bool> vec;
			for (int j = 0; j < size; j++)
				if (i == j)
					vec.push_back(true);
				else if (j - i == 1 && s[i] == s[j])
					vec.push_back(true);
				else
					vec.push_back(false);
		}
		for (int step  = 3; step <= size; step ++)
			for (int i = 0; i <= size - step; i++)
				if (s[i] == s[i+step-1] && matrix[i+1][i+step-2])
					vec[i][i+step-1] = true;
		for (int i = 0; i < size; i++)
		{
			if (matrix[0][i])
			{
				vector<vector<string> >subVec = subPartition(s.substr(i + 1, s.npos), i+1);
				int subSize = subVec.size();
				for (int j = 0; j < subSize; j++)
				{
					vector<string> vec;
					vec.push_back(s.substr(0, i + 1));
					int subSubSize = subVec[j].size();
					for (int k = 0; k  < subSubSize; k++)
						vec.push_back(subVec[j][k]);
					returnVec.push_back(vec);
				}
			}
		}
		return returnVec;
	}
	vector<vector<string> > subPartition (string s, int index)
	{
		vector<vector<string> > returnVec;
		int size = s.size();
		if (size == 0)
		{
			vector<string> vec;
			returnVec.push_back(vec);
			return returnVec;
		}
		for (int i = 0; i < size; i++)
			if (matrix[index][i+index])
			{
				vector<vector<string> > subVec = subPartition(s.substr(i + 1, s.npos), index + i + 1);
				int subSize = subVec.size();
				for (int j = 0; j < subSize; j++)
				{
					vector<string> vec;
					vec.push_back(s.substr(0, i+1));
					int subSubSize = subVec[j].size();
					for (int k = 0; k < subSubSize; k++)
						vec.push_back(subVec[j][k]);
					returnVec.push_back(vec);
				}
			}
		return returnVec;
	}
};
