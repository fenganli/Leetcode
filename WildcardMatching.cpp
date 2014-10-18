class Solution
{
	public:
	bool isMatch(const char * s, const char *p)
	{
		int sizeS = strlen(s);
		int sizeP = strlen(p);
		if (sizeP == 0)
			if (sizeS == 0)
				return true;
			else
				return false;
		p = trimStar(p);
		vector<vector<bool> > matrix;
		for (int i = 0; i <= sizeS; i++)
		{
			vector<bool> vec;
			for (int j = 0; j <= sizeP; j++)
				vec.push_back(false);
			matrix.push_back(vec);
		}
		matrix[sizeS][sizeP] = true;
		for (int j = sizeP - 1; j >= 0; j--)
			if (p[j] == '*' && matrix[sizeS][j+1])
				matrix[sizeS][j] = true;
		for (int j = sizeP - 1; j >= 0; j--)
		{
			for (int i = sizeS - 1; i >= 0; i--)
			{
				if (p[j] == '?')
					matrix[i][j] = matrix[i+1][j+1];
				else if (p[j] == '*')
				{	
					if (p[j+1] != '*')
					{
						for (int k = i; k <= sizeS; k++)
							if (matrix[k][j+1])
							{
								matrix[i][j] = true;
								break;
							}
					}
					else
						matrix[i][j] = matrix[i][j+1];
					
				}
				else
				{
					if (p[j] == s[i])
						matrix[i][j] = matrix[i+1][j+1];
					else
						matrix[i][j] = false;
				}
			}
		}
		return matrix[0][0];
	}
	char * tripStar(char * p)
	{
		int size = strlen(p);
		curIndex = 0;
		for (int i = 1; i < size; i++)
		{
			if (p[i] == '*' && p[curIndex] == '*')
				continue;
			else
				p[++curIndex] = p[i];
		}
		p[curIndex+1] = '\0';
		return p;
	}
};
