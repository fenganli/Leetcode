class Solution
{
	public:
	string convert(string s, int nRows)
	{
		vector<vector<char> > matrix;
		int size = s.size();
		if (size <= 1)
			return s;
		int nCols = (size / nRows + 1) * 2 + 1;
		for (int i = 0; i < nRows; i++)
		{
			vector<char> vec;
			for (int j = 0; j < nCols; j++)
				vec.push_back(' ');
			matrix.push_back(vec);
		}
		int colNum = 0;
		for (int i = 0; i < size; )
		{
			if (colNum % (nRows-1)  == 0)
			{
				for (int j = 0; j < nRows; j++)
					matrix[j][colNum] = s[j+i];
				i = i + nRows;
				colNum++;
			}
			else
			{
				matrix[nRows - 1 - colNum % (nRows-1)][colNum] = s[i];
				i++;
				colNum++;
			}
		}
		string returnStr = "";
		for (int i = 0; i < nRows; i++)
		{
			if (i % 2 == 0)
			{
				for (int j = 0; j < colNum; j++)
					if (matrix[i][j] != ' ')
						returnStr += matrix[i][j];
			}
			else
			{
				for (int j = 0; j < colNum; j++)
					if (matrix[i][j] != ' ')
						returnStr += matrix[i][j];
			}
		}
		return returnStr;
	}
};
