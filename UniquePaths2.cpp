class Solution
{
	public:
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
	{
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		if (n == 0)
			return 0;
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
				if (obstacleGrid[i][j] == 0)
					path[i][j] = path[i+1][j] + path[i][j+1];
				else
					path[i][j] = 0;
		return path[0][0];
	}
};
