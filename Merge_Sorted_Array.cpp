class Solution
{
	public:
	void merge(int A[], int m, int B[], int n)
	{
		int * returnArray = new int[m+n];
		int indexA = 0;
		int indexB = 0;
		int indexC = 0;
		while (indexA != m || indexB != n)
		{
			int flag = 0;
			if (indexA != m && indexB != n)
				if (A[indexA] < B[indexB])
					flag = 0;
				else
					flag = 1;
			else if (indexA != m)
				flag = 0;
			else
				flag = 1;
			if (flag == 0)
				returnArray[indexC++] = A[indexA++];
			else
				returnArray[indexC++] = B[indexB++];
		}
		for (int i = 0; i < m+n; i++)
			A[i] = returnArray[i];
	}
};
					
			

