class Solution
{
	public:
	void solve(vector<vector<char> > &board)
	{
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		if (n == 0)
			return;
		for (int j = 0; j < n; j++)
		{
			if (board[0][j] == 'O')
				search(board, 0, j);
			if (board[m-1][j] == 'O')
				search(board, m-1, j);
		}
		for (int i = 1; i < m - 1; i++)
		{
			if (board[i][0] == 'O')
				search(board, i, 0);
			if (board[i][m-1] == 'O')
				search(board, i , m - 1);
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == '!')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
		return;
	}
	void search(vector<vector<char> > &board, int i, int j)
	{
		int m = board.size();
		int n = board[0].size();
		if (i < 0 || j < 0 || i >= m || j >= n)
			return;
		if (board[i][j] == 'O')
		{
			board[i][j] = '!';
			search(board, i-1,j);
			search(board, i+1,j);
			search(board, i, j+1);
			search(board, i, j-1);
		}
		//else
		return;
	}
};
