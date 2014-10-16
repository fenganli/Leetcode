class Solution
{
	public:
	int numTrees (int n)
	{
		int * p = new int[n+1];
		p[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			p[i] = 0;
			for (int j = 1; j <= i; j++)
				p[i] += p[j-1] * p[i-j];
		}
		return p[n];
	}
};
