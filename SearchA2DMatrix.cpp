class Solution
{
	public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		int m  = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		int left = 0, right = m * n, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (matrix[mid / n][mid % n] == target)
				return true;
			else if (matrix[mid / n][mid % n] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return false;
	}
};
