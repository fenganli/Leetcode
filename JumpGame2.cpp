class Solution
{
	public:
	int jump(int A[], int n)
	{
		int stepNum = 0;
		int left = 0, right = 1;
		while (right < n)
		{
			int temp = right;
			int reach = 0;
			for (int i = left; i < right && i < n; i++)
				if (reach == 0)
					reach = i + A[i];
				else
					reach = max(reach, i + A[i]);
			right = reach + 1;
			left = temp;
			stepNum++;
		}
		return stepNum;
	}	
};
