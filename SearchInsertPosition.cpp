class Solution
{
	public:
	int searchInsert(int A[], int n, int target)
	{
		int left = 0, right = n, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (A[mid] == target)
				return mid;
			else if (A[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
