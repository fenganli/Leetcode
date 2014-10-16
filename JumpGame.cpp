class Solution
{
	public:
	bool canJump(int A[], int n)
	{
		int reach = 0;
		for (int i = 0; i < n; i++)
		{
			if (i > reach)
				break;
			reach = max(reach, i + A[i]);
		}
		if (reach >= n-1)
			return true;
		else
			return false;
	}
};
