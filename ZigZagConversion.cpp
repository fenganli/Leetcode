class Node
{
	public:
	int x, y;
	Node (int row, int col):x(row), y(col) {}
};
class Solution
{
	public:
	string convert(string s, int nRows)
	{
		int size = s.size();
		if (size <= 1)
			return s;
		if (nRows == 1)
		    return s;
		Node end = getIndex(size - 1, nRows);
		int rowMax = end.x, colMax = end.y;
		string returnStr = "";
		for (int i = 0; i < nRows; i++)
			if (i == 0 || i == nRows - 1)
			{
				for (int j = 0; j <= colMax; j += nRows -1)
					if (j < colMax || i <= rowMax)
						returnStr += s[getNum(Node(i, j), nRows)];
			}
			else
			{
				for (int j = 0; j <= colMax; j++)
					if (j % (nRows - 1) == 0 || j % (nRows -1) == (nRows-1-i))
						if (j < colMax || i <= rowMax)
							returnStr += s[getNum(Node(i, j), nRows)];
			}
		return returnStr;
	}
	Node getIndex(int num, int nRows)
	{
		int patternNum = num / (nRows + nRows - 2);
		num = num % (nRows + nRows - 2);
		if (num < nRows)
		{
			return Node (num , patternNum * (nRows - 1));
		}
		else
		{
			num = num - nRows;
			return Node (nRows - 2 - num, patternNum * (nRows - 1) + 1 + num);
		}
	}
	int getNum(Node node , int nRows)
	{
		int rowNum = node.x, colNum = node.y;
		int patternNum = colNum / (nRows - 1);
		colNum = colNum % (nRows - 1);
		if (colNum == 0)
			return patternNum * (nRows + nRows - 2) + rowNum;
		else
			return patternNum * (nRows + nRows - 2) + nRows + (colNum) - 1;
	}
};

