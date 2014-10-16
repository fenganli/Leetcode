class Solution
{
	public:
	void setZeros (vector<vector<int> > &matrix)
	{
		int size1 = matrix.size();
		if (size1 == 0)
			return;
		int size2 = matrix[0].size();
		if (size2 == 0)
			return;
		int rowNum, colNum;
		bool found = false;
		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++)
			{
				if (matrix[i][j] == 0 && !found)
				{
					found = true;
					rowNum = i;
					colNum = j;
				}
				else if (matrix[i][j] == 0)
				{
					matrix[rowNum][j] = 0;
					matrix[i][colNum] = 0;
				}
			}
		for (int i = 0; i < size1; i++)
			for (int j = 0; j < size2; j++)
				if (matrix[rowNum][j] == '0' || matrix[i][colNum] == '0')
					matrix[i][j] = 0;
		return;
	}
};
