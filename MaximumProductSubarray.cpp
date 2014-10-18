class Extreme
{
	int min, max;
	public:
	Extreme(int x, int y): min(x), max(y){}
	int getMin()
	{
		return min;
	}
	int getMax()
	{
		return max;
	}
};
class Solution
{
	public:
	int maxProduct(int A[], int n)
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return A[0];
		int maxNum = 0;
		vector<Extreme> vec;
		vec.push_back(Extreme(A[0], A[0]));
		maxNum = max(maxNum, vec[0].getMax());
		for (int i = 1; i < n; i++)
		{
			if (A[i] >= 0)
				vec.push_back(Extreme(min(A[i], A[i] * vec[i-1].getMin()), max(A[i], A[i] * vec[i-1].getMax())));
			else
				vec.push_back(Extreme(min(A[i], A[i] * vec[i-1].getMax()), max(A[i], A[i] * vec[i-1].getMin())));
			maxNum = max(vec[i].getMax(), maxNum);
		}
		return maxNum;
	}
};
