class Solution
{
	public:
	int removeDuplicates(int A[], int n)
	{
		if (n == 0)
			return 0;
		bool first = true;
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[i] == A[index])
			{
				if (first)
				{
					A[++index] = A[i];
					first = false;
				}
			}
			else
			{
				A[++index] = A[i];
				first = true;
			}
		}
		return index + 1;
	}
};
