class Solution
{
	public:
	void rotate (vector<vector<int> > & matrix)
	{
		int size = matrix.size();
		int n = size / 2;
		for (int i = 0; i < (size+1)/2; i++)
			for (int j = 0; j < n; j++)
			{
				int mem = matrix[i][j];
				matrix[i][j] = matrix[size-1-j][i];
				matrix[size-1-j][i] = matrix[size-1-i][size-1-j];
				matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
				matrix[j][size-1-i] = mem;
			}
	}
};
