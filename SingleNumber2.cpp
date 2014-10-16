class Solution
{
public:
	int singleNumber(int A[], int n)
	{
		int bitCount[32];
		for (int i = 0; i < 32; i++)
			bitCount[i] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 32; j++)
				if (getI(A[i], j))
					bitCount[j]++;
		}
		for (int i = 0; i < 32; i++)
			bitCount[i] = bitCount[i] % 3;
		int result = 0;
		for (int i = 0; i < 32; i ++)
			if (bitCount[i] == 1)
				result |= 1 << i;
		return result;
	}
	bool getI(int x, int y)
	{
		return (x >> y) & 1 == 1;
	}
};