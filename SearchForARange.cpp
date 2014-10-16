class Solution
{
	public:
	vector<int> searchRange (int A[], int n, int target)
	{
		int left = 0, right = n, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (A[mid] == target)
				break;
			else if (A[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == right)
		{
			vector<int> vec;
			vec.push_back(-1);
			vec.push_back(-1);
			return vec;
		}
		int left2 = left, right2 = mid + 1, mid2;
		while(true)
		{
			mid2 = (left2 + right2) / 2;
			if (A[mid2] < target)
				left2 = mid2 + 1;
			else
				if (mid2 == 0 || A[mid2 - 1] < target)
					break;
				else
					right2 = mid2;
		}
		int left3 = mid, right3 = right, mid3;
		while (true)
		{
			mid3 = (left3 + right3) / 2;
			if (A[mid3] > target)
				right3 = mid3;
			else
				if (mid3 == n - 1 || A[mid3 + 1] > target)
					break;
				else
					left3 = mid3  + 1;
		}
		vector<int> vec;
		vec.push_back(mid2);
		vec.push_back(mid3);
		return vec;
	}
};
