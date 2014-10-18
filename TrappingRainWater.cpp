#include <iostream>
using namespace std;
class Solution
{
public:
	int trap(int A[], int n)
	{
		int water = 0;
		int left = 0, leftIndex = 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (left == 0)
			{
				left = A[i];
				leftIndex = i;
			}
			else
			{
				if (A[i] >= left)
				{
					water += count;
					count = 0;
					left = A[i];
					leftIndex = i;
				}
				else
					count += left - A[i];
			}
		}
		int right = 0;
		count = 0;
		for (int i = n - 1; i >= leftIndex; i--)
		{
			if (right == 0)
				right = A[i];
			else
			{
				if (A[i] >= right)
				{
					water += count;
					count = 0;
					right = A[i];
				}
				else
					count += right - A[i];
			}
		}
		return water;
	}
};
