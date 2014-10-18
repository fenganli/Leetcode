class Solution
{
	public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int> > path;
		for (int i = 0; i <= m; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= n; j++)
				vec.push_back(0);
			path.push_back(vec);
		}
		path[m][n-1] = 1;
		for (int i = m - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--)
				path[i][j] = path[i+1][j] + path[i][j+1];
		return path[0][0];
	}
};	
