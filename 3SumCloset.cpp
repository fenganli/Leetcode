#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
	int threeSumClosest(vector<int> & num, int target)
	{
		int threeSum = 0;
		bool updated = false;
		sort(num.begin(), num.end());
		int size = num.size();
		for (int i = 0; i < size - 2; i++)
			for (int j = i + 1; j < size - 1; j++)
			{
				int searchTarget = target - num[i] - num[j];
				int closet = search(num, j + 1, size, searchTarget);
				int sum = num[i] + num[j] + closet;
				if (!updated)
				{
					threeSum = sum;
					updated = true;
				}
				else
					if (abs(sum-target) < abs(threeSum-target))
						threeSum = sum;
			}
		return threeSum;
	}
	int search(vector<int> & num, int l, int r, int target)
	{
		int left = l, right = r;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (num[mid] == target)
				return target;
			else if (num[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (right == r)
			return num[r-1];
		else if (right == l)
			return num[l];
		else
			return abs(num[right-1] - target) < abs(num[right] - target) ? num[right - 1] : num[right];
	}
};