class Solution
{
	public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int medianNum = findK(A, m, B, n, (m+n) / 2);
		if ((m + n) % 2 == 1)
			return medianNum;
		else
		{
			int medianLess = findK(A, m, B, n, (m+n) / 2 - 1);
			return (medianNum + medianLess) / 2.0;
		}
	}
	int findK(int A[], int m, int B[], int n, int k)
	{
		if (m == 0)
			return B[k];
		if (n == 0)
			return A[k];
		int aIndex = m / 2;
		int searchNum = A[aIndex];
		int bIndex = search(B, n, searchNum);
		if (k == aIndex + bIndex)
			return searchNum;
		else if (k < aIndex + bIndex)
			return findK(A, aIndex, B, bIndex, k);
		else
			return findK(A + aIndex + 1, m - aIndex - 1, B + bIndex, n - bIndex, k - aIndex - bIndex - 1);
	}
	int search(int A[], int n, int num)
	{
		int left = 0, right = n, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (A[mid] == num)
				return mid;
			else if (A[mid] < num)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
