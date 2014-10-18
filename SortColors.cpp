class Solution
{
	public:
	void sortColors(int A[], int n)
	{
		int left = 0, right = n - 1;
		int swapIndex = 0;
		while (left <= right)
		{
		    if (swapIndex > right)
		        break;
		    if (A[swapIndex] == 1)
		        swapIndex ++;
		    else if (A[swapIndex] == 0)
		    {
		        if (swapIndex == left)
		        {
		            left++;
		            swapIndex++;
		        }
		        else
		        {
		            A[left++] = 0;
		            A[swapIndex] = 1;
		            swapIndex++;
		        }
		    }
		    else
		    {
		        if (swapIndex == right)
		            break;
		        else
		        {
		            A[swapIndex] = A[right];
		            A[right--] = 2;
		        }
		    }
		}
	}
};
