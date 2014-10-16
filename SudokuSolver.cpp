class CellCount
{
	int x;
	int y;
	int count;
public:
	CellCount(int _x, int _y, int _count):x(_x), y(_y), count(_count) {}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getCount() const
	{
		return count;
	}
};
bool cmp(const CellCount & T1, const CellCount & T2)
{
	return T1.getCount() < T2.getCount();
}
class Solution
{
	bool matrix[9][9][10];
public:
	void solveSudoku(vector<vector<char> > &board)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				for (int k = 1; k <= 9; k++)
					matrix[i][j][k] = true;
		int filledCount = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.')
				{
					filledCount++;
					eliminate(i, j, board[i][j] - '0');
				}
		//cout << filledCount << endl;
		search(filledCount, board);
		return;
	}
	bool search(int step, vector<vector<char> > &board)
	{
		if (step == 81)
			return true;
		CellCount minNum(0,0,100);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9;j++)
				if (board[i][j] == '.')
				{
				    int count = 0;
				    for (int k = 1; k <= 9; k++)
				        if (matrix[i][j][k])
				            count++;
					if (count < minNum.getCount())
					    minNum = CellCount(i, j, count);
				}
		if (minNum.getCount() == 0)
			return false;
		int x = minNum.getX();
		int y = minNum.getY();
		for (int k = 1; k <= 9; k++)
		{
			if (matrix[x][y][k] == false)
			    continue;
			board[x][y] = (char)(k + '0');
			vector<pair<int, int> > eVec = eliminate(x, y, k);
			if (search(step + 1, board))
				return true;
			for (vector<pair<int, int> >::iterator eIter = eVec.begin(); eIter != eVec.end(); eIter++)
			    matrix[eIter -> first][eIter -> second][k] = true;
			board[x][y] = '.';
		}
		return false;
	}
	vector<pair<int, int> > eliminate(int row, int col, int num)
	{
	    vector<pair<int, int> > returnVec;
		for (int j = 0; j < 9; j++)
		{
		    if (matrix[row][j][num])
		    {
		        matrix[row][j][num] = false;
		        returnVec.push_back(make_pair(row, j));
		    }
		}
		for (int i = 0; i < 9; i++)
		{
		    if (matrix[i][col][num])
		    {
		        matrix[i][col][num] = false;
		        returnVec.push_back(make_pair(i, col));
		    }
		}
		int startI = (row / 3) * 3;
		int startJ = (col / 3) * 3;
		for (int i = startI; i < startI + 3; i++)
			for (int j = startJ; j < startJ + 3; j++)
			{
			    if (matrix[i][j][num])
			    {
			        matrix[i][j][num] = false;
			        returnVec.push_back(make_pair(i, j));
			    }
			}
		return returnVec;;
	}
};