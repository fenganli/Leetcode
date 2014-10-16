class Solution
{
	vector<vector<bool> > matrix;
	vector<vector<bool> > query;
	vector<bool> multiple;
	char * newS;
	char * newP;
	int sSize;
	int pSize;
public:
	bool isMatch(const char *s, const char * p)
	{
		sSize = strlen(s);
		pSize = strlen(p);
		newS = new char[sSize + 1];
		memcpy(newS, s, sizeof(char) * (sSize + 1));
		newP = new char[pSize + 1];
		memcpy(newP, p, sizeof(char) * (pSize + 1));
		newP = trimStar(newP);
		pSize = strlen(newP);
		for (int i = 0; i <= sSize; i++)
		{
			vector<bool> vec;
			for (int j = 0; j <= pSize; j++)
				vec.push_back(false);
			matrix.push_back(vec);
			query.push_back(vec);
		}
		for (int i = 0; i < sSize; i++)
		{
			matrix[i][pSize] = false;
			query[i][pSize] = true;
		}
		matrix[sSize][pSize] = true;
		query[sSize][pSize] = true;
		for (int j = pSize - 1; j >= 0; j--)
		{
			if (multiple[j] && matrix[sSize][j+1])
				matrix[sSize][j] = true;
			else
				matrix[sSize][j] = false;
			query[sSize][j]  = true;
		}
		return search(0, 0);
	}
	bool search(int sIndex, int pIndex)
	{
		if (query[sIndex][pIndex])
			return matrix[sIndex][pIndex];
		bool result = false;
		if (!multiple[pIndex])
		{
			if (newP[pIndex] == '.')
			{
				if (search(sIndex + 1, pIndex + 1))
					result = true;
			}
			else if (newP[pIndex] == newS[sIndex] && search(sIndex + 1, pIndex + 1))
				result = true;
		}
		else
		{
			if (newP[pIndex] == '.')
			{
				for (int i = sIndex; i <= sSize; i++)
				{
					if (search(i, pIndex+1))
					{
						result = true;
						break;
					}
				}
			}
			else
			{
				for (int i = sIndex; i <= sSize; i++)
				{
					if (search(i, pIndex + 1))
					{
						result = true;
						break;
					}
					if (i != sSize && newS[i] != newP[pIndex])
						break;
				}
			}
		}
		matrix[sIndex][pIndex] = result;
		query[sIndex][pIndex] = true;
		return result;
	}
	char * trimStar(char *p)
	{
		int size = strlen(p);
		int curIndex = 0;
		for (int i = 1; i < size; i++)
			if (p[i] == '*' && p[curIndex] == '*')
				continue;
			else
				p[++curIndex] = p[i];
		p[++curIndex] = '\0';
		for (int i = 0; i < curIndex; i++)
			multiple.push_back(false);
		size = strlen(p);
		curIndex = 0;
		for (int i = 1; i < size; i++)
			if (p[i] == '*')
				multiple[curIndex] = true;
			else
				p[++curIndex] = p[i];
		p[++curIndex] = '\0';
		return p;
	}
};
