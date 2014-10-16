class Solution
{
	vector<vector<bool> > myBoard;
	public:
	bool exist (vector<vector<char> >&board, string word)
	{
		int size = word.size();
		int m = board.size();
		if (m == 0)
			if (size == 0)
				return true;
			else
				return false;
		int n = board[0].size();
		if (n == 0)
			if (size == 0)
				return true;
			else
				return false;
		if (size == 0)
			return true;
		for (int i = 0; i < m; i++)
		{
			vector<bool> vec;
			for (int j = 0; j < n; j++)
				vec.push_back(true);
			myBoard.push_back(vec);
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{
					myBoard[i][j] = false;
					if (search(board, 1, word, size, i, j))
						return true;
					myBoard[i][j] = true;
				}
			}
		return false;
	}
	bool search(vector<vector<char> >&board, int step, string word, int size, int x, int y)
	{
		if (step == size)
			return true;
		int m = board.size();
		int n = board[0].size();
		if (x > 0 && board[x-1][y] == word[step] && myBoard[x-1][y])
		{
			myBoard[x-1][y] = false;
			if (search(board, step + 1, word, size, x - 1, y))
				return true;
			myBoard[x-1][y] = true;
		}
		if (x < m - 1 && board[x + 1][y] == word[step] && myBoard[x + 1][y])
		{
			myBoard[x+1][y] = false;
			if (search(board, step + 1, word, size, x + 1, y))
				return true;
			myBoard[x+1][y] = true;
		}
		if (y > 0 && board[x][y-1] == word[step] && myBoard[x][y-1])
		{
			myBoard[x][y-1] = false;
			if (search(board, step + 1, word, size, x, y - 1))
				return true;
			myBoard[x][y-1] = true;
		}
		if (y < n - 1 && board[x][y+1] == word[step] && myBoard[x][y+1])
		{
			myBoard[x][y+1] = false;
			if (search(board, step + 1, word, size, x, y + 1))
				return true;
			myBoard[x][y+1] = true;
		}
		return false;
	}
};
