class CellCount
{
	int x, y, count;
	public:
	Count(int _x, int _y, int _count):x(_x), y(_y), count(_count) {}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getCount()
	{
		return count;
	}
};
bool cmp(const CellCount & T1, const CellCount & T2)
{
	return T1.count < T2.count;
}
class Solution
{
	unordered_set<int> matrix[9][9];
	public:
	void solveSudoku(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				for (int k = 1; k <= 9; k++)
					matrix[i][j].insert(k);
		int filledCount = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != ' ')
				{
					filledCount++;
					eliminate(i, j, board[i][j] - '0');
				}
		search(filledCount, board);
		return;
	}
	bool search(int step, vector<vector<char> > &board)
	{
		if (step == 81)
			return true;
		vector<CellCount> vec;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9;j++)
				if (board[i][j] == ' ')
					vec.push_back(CellCount(i, j, matrix[i][j].size()));
		sort(vec.begin(), vec.end(), cmp);
		int size = vec.size();
		if (vec[0].getCount() == 0)
			return false;
		unordered_set<int> memory[9][9];
		for (int j = 0;j < 9; j++)
			for (int k = 0; k < 9; k++)
				memory[j][k] = matrix[j][k];
		for (int i = 0; i < size; i++)
		{
			int x = vec[i].getX();
			int y = vec[j].getY();
			for (unordered_set<int>::iterator iter = matrix[x][y].begin(); iter != matrix[x][y].end(); iter++)
			{
				board[x][y] = (char)(*iter + '0');
				eliminate(x, y, *iter + '0');
				if (search(step + 1, board))
					return true;
				for (int j = 0; j < 9; j++)
					for (int k = 0; k < 9; k++)
						matrix[j][k] = memory[j][k];
				board[x][y] = ' ';
			}
		}
		return false;
	}
	void eliminate(int row, int col, int num)
	{
		for (int j = 0; j < 9; j++)
			matrix[row][j].erase(num);
		for (int i = 0; i < 9; i++)
			matrix[i][col].erase(num);
		int startI = (row / 3) * 3;
		int startJ = (col / 3) * 3;
		for (int i = startI; i < startI + 3; i++)
			for (int j = startJ; j < startJ + 3; j++)
				matrix[i][j].erase(num);
		return;
	}
};
