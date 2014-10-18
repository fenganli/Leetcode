class Solution
{
	public:
	int firstMissingPositive(int A[], int n)
	{
		if (n == 0)
			return 1;
		for (int i = 0; i < n; i++)
			if (A[i] <= 0 || A[i] > n)
				A[i] = 0;
		for (int i = 0; i < n; i++)
			if (A[i] == 0)
				continue;
			else
			{
				int index = A[i];
				A[i] = 0;
				while (true)
				{
					if (A[index - 1] == 0)
					{
						A[index-1] = index;
						break;
					}
					else if (A[index - 1] == index)
						break;
					else
					{
						int swap = A[index - 1];
						A[index-1] = index;
						index = swap;
					}

				}
			}
		for (int i = 0; i < n; i++)
			if (A[i] == 0)
				return i + 1;
		return n + 1;
	}
};