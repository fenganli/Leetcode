class Solution
{
public:
    int numDistinct(string s, string T)
	{
		int sSize = s.size();
		int tSize = T.size();
		int mat[sSize+1][tSize+1];
		for (int i = 0; i <= sSize; i++)
			for (int j = 0; j <= tSize; j++)
				mat[i][j] = 0;
	    for (int i = sSize - 1; i >= 0; i--)
			for (int j = tSize - 1; j >= tSize + i - sSize && j >= 0; j--)
			{
                    if (T[j] == s[i])
                        if (j == tSize - 1)
                            mat[i][j] = 1 + mat[i+1][j];
                        else
                            mat[i][j] = mat[i+1][j+1] + mat[i+1][j];
                    else
                        mat[i][j] = mat[i+1][j];
			 }
		return mat[0][0];
	}
};
